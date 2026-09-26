#include "POSsystem.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>

void POSsystem::run() {
    // 1. 加载商品库存
    itemmanager.CSVread();
    if (itemmanager.empty()) {
        // 默认三商品
        itemmanager.add(Item("Cola",     "001", 3.50, 70));
        itemmanager.add(Item("Lollipop", "002", 0.50, 80));
        itemmanager.add(Item("Noodles",  "003", 6.00, 20));
    }

    std::cout << "=== Dian POS ===\n";
    std::cout << "Type 'exit' or 'quit' to quit.\n";

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) continue;

        if (is_admin) {
            pos_admin(line);
            continue;
        }

        // 收银员模式
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd == "exit" || cmd == "quit") break;

        if (cmd == "print") {
            pos_print();
        } else if (cmd == "drop") {
            pos_drop();
        } else if (cmd == "checkout") {
            pos_checkout();
        } else if (cmd == "newday") {
            pos_newday();
        } else if (cmd == "admin") {
            enter_admin();
        } else if (cmd == "prices") {
            itemmanager.print();      // 收银员暂时也显示库存，可后续优化
        } else if (cmd == "sales") {
            int day;
            if (iss >> day) pos_sales(day);
            else pos_sales(0);        // 0 表示今天
        } else {
            // 可能是条码或 -条码，支持一行多个
            std::string token = cmd;
            do {
                if (token[0] == '-') pos_reduce(token.substr(1));
                else pos_scan(token);
            } while (iss >> token);
        }
    }
}

void POSsystem::pos_scan(const std::string& code) {
    const Item* p = itemmanager.find(code);
    if (!p) {
        std::cout << "ERROR: code not found\n";
        return;
    }

    int in_cart = cart.get_qty(code);
    if (in_cart + 1 > p->get_stock()) {
        std::cout << "ERROR: " << p->get_name()
                  << " only " << p->get_stock()
                  << " left, cannot add more.\n";
        return;
    }

    cart.add_item(*p);
    int now_qty = cart.get_qty(code);
    std::printf("%-10s%-10.2f x%d = %.2f\n",
                p->get_name().c_str(),
                p->get_price(),
                now_qty,
                p->get_price() * now_qty);
}

void POSsystem::pos_reduce(const std::string& code) {
    if (!cart.has(code)) {
        std::cout << "ERROR: " << code << " not in cart.\n";
        return;
    }

    const Item* p = cart.find_item(code);
    if (!p) return;

    cart.rdc_item(*p);
    if (cart.has(code)) {
        int now_qty = cart.get_qty(code);
        std::printf("%-10s%-10.2f x%d = %.2f\n",
                    p->get_name().c_str(),
                    p->get_price(),
                    now_qty,
                    p->get_price() * now_qty);
    } else {
        std::cout << "Removed " << code << " from cart.\n";
    }
}

void POSsystem::pos_print() {
    cart.print_receipt();
}

void POSsystem::pos_drop() {
    cart.drop();
    std::cout << "Cart dropped.\n";
}

void POSsystem::pos_checkout() {
    if (cart.empty()) {
        std::cout << "Cart is empty.\n";
        return;
    }

    // 1. 检查库存
    for (const auto& [code, line] : cart.items()) {
        const Item* p = itemmanager.find(code);
        if (!p) {
            std::cout << "ERROR: Item " << code << " not found.\n";
            return;
        }
        if (p->get_stock() < line.get_stock()) {
            std::cout << "ERROR: Stock not enough for " << p->get_name() << ".\n";
            return;
        }
    }

    // 2. 扣库存
    for (const auto& [code, line] : cart.items()) {
        itemmanager.reduce_stock(code, line.get_stock());
    }
    // reduce_stock 内部会 CSVwrite，这里不再重复

    // 3. 生成 Sale（内部打印小票并清空 cart）
    Sale sale = cart.checkout();

    // 4. 写销售流水
    salemanager.add_record(sale);

    std::cout << "Checkout successful!\n";
}

void POSsystem::pos_sales(int day) {
    if (day == 0) salemanager.sales_check();
    else salemanager.sales_check(day);
}

void POSsystem::pos_newday() {
    salemanager.new_day();
    std::cout << "New day started. Today's sales records cleared.\n";
}

void POSsystem::enter_admin() {
    std::cout << "Password: ";
    std::string pwd;
    std::getline(std::cin, pwd);
    if (pwd == "admin123") {
        is_admin = true;
        std::cout << "Admin mode.\n";
    } else {
        std::cout << "Wrong password.\n";
    }
}

void POSsystem::exit_admin() {
    is_admin = false;
    std::cout << "Bye.\n";
}

void POSsystem::pos_admin(const std::string& line) {
    std::istringstream iss(line);
    std::string cmd;
    iss >> cmd;

    if (cmd == "back") {
        exit_admin();
    } else if (cmd == "prices") {
        itemmanager.print();
    } else if (cmd == "setprice") {
        std::string code; double price;
        if (iss >> code >> price) {
            itemmanager.set_price(code, price);
            std::cout << "Price updated.\n";
        } else {
            std::cout << "Usage: setprice <code> <price>\n";
        }
    } else if (cmd == "itemadd") {
        std::string code, name; double price;
        if (iss >> code >> name >> price) {
            itemmanager.add(Item(name, code, price, 0));
            std::cout << name << "(" << code << ") added.\n";
        } else {
            std::cout << "Usage: itemadd <code> <name> <price>\n";
        }
    } else if (cmd == "itemdel") {
        std::string code;
        if (iss >> code) {
            itemmanager.remove(code);
            std::cout << "Item " << code << " removed.\n";
        } else {
            std::cout << "Usage: itemdel <code>\n";
        }
    } else if (cmd == "restock") {
        std::string code; int qty;
        if (iss >> code >> qty) {
            itemmanager.add_stock(code, qty);
            std::cout << "Restocked.\n";
        } else {
            std::cout << "Usage: restock <code> <qty>\n";
        }
    } else if (cmd == "setstock") {
        std::string code; int qty;
        if (iss >> code >> qty) {
            itemmanager.set_stock(code, qty);
            std::cout << "Stock set.\n";
        } else {
            std::cout << "Usage: setstock <code> <qty>\n";
        }
    } else {
        std::cout << "Unknown admin command.\n";
    }
}