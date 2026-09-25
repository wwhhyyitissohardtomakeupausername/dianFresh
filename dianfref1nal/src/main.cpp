#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <map>

#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include "SaleManager.hpp"

std::map<std::string, Item> items;
Cart cart;
SaleManager manager;

int main() {
    // Level 1 初始商品
    items["001"] = Item("Cola", "001", 3.50, 70);
    items["002"] = Item("Lollipop", "002", 0.50, 80);
    items["003"] = Item("Noodles", "003", 6.00, 20);

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd.empty()) continue;

        if (cmd == "exit" || cmd == "quit") {
            break;
        }
        else if (cmd == "prices") {
            std::printf("Item No. Pri.\n");
            for (const auto& [code, item] : items) {
                std::printf("%-10s %-5s %.2f\n",
                            item.get_name().c_str(),
                            code.c_str(),
                            item.get_price());
            }
        }
        else if (cmd == "print") {
            cart.print_receipt();
        }
        else if (cmd == "drop") {
            cart.drop();
        }
        else if (cmd == "checkout") {
            Sale sale = cart.checkout();
            manager.add_record(sale);
        }
        else if (cmd == "sales") {
            int day;
            if (iss >> day) manager.sales_check(day);
            else manager.sales_check();
        }
        else if (cmd == "newday") {
            manager.new_day();
            std::printf("New day started. Today's sales records cleared.\n");
        }
        else {
            // 否则按条码处理，支持一行多个条码，例如：001 001 -002
            std::istringstream codes(line);
            std::string code;
            while (codes >> code) {
                bool minus = false;
                if (code[0] == '-') {
                    minus = true;
                    code = code.substr(1);
                }

                const Item& it = items.at(code);
                if (minus) cart.rdc_item(it);
                else cart.add_item(it);
            }

            // 如果想每次扫描后立刻看到当前购物车，取消下面这行注释
            // cart.print_receipt();
        }
    }

    return 0;
}