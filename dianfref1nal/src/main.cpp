#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <map>

#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include "SaleManager.hpp"
#include "ItemManager.hpp"

std::map<std::string, Item> items;
Cart cart;
SaleManager salemanager;
ItemManager itemmanager;
int main() {
    //初始仓库信息读取
    itemmanager.CSVread();
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
            itemmanager.print();
        }
        else if (cmd == "print") {
            cart.print_receipt();
        }
        else if (cmd == "drop") {
            cart.drop();
        }
        else if (cmd == "checkout") {
            Sale sale = cart.checkout();
            salemanager.add_record(sale);
        }
        else if (cmd == "sales") {
            int day;
            if (iss >> day) salemanager.sales_check(day);
            else salemanager.sales_check();
        }
        else if (cmd == "newday") {
            salemanager.new_day();
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