#include "Item.hpp"
#include "ItemManager.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
void ItemManager::CSVwrite() {
    std::ofstream out("data/warehouse.csv", std::ios::trunc);
    for (const auto& [code, item] : items) {
        out << code << ','
        << item.get_name() << ','
        << item.get_price() << ','
        << item.get_stock() << '\n';
    }
}
void ItemManager::CSVread() {
    std::ifstream in("data/warehouse.csv");
    items.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string code, name, price_str, stock_str;

        std::getline(iss, code, ',');
        std::getline(iss, name, ',');
        std::getline(iss, price_str, ',');
        std::getline(iss, stock_str, ',');

        items[code]=Item(name,code,
        std::stod(price_str),
        stoi(stock_str));

    }
}
void ItemManager::set_price(const std::string& code, double newprice) {
    items[code].set_price(newprice);
    CSVwrite();
}
void ItemManager::add(const Item& item) {
    items[item.get_code()]=item;
    CSVwrite();
}
void ItemManager::remove(const std::string& code) {
    items.erase(code);
    CSVwrite();
}
void ItemManager::set_stock(const std::string& code, int stock) {
    items[code].set_stock(stock);
    CSVwrite();
}
void ItemManager::add_stock(const std::string& code, int delta) {
    items[code].set_stock(items[code].get_stock()+delta);
    CSVwrite();
}
void ItemManager::reduce_stock(const std::string& code, int qty) {
    items[code].set_stock(items[code].get_stock()-qty);
    CSVwrite();
}
void ItemManager::print() const {
    printf("%-10s%-5s%-5s%-10s\n","Item","No.","Pri.","Stock");
    for(int i=0;i<+30;i++){printf("-");}
    printf("\n");
    for (const auto& [code, item] : items) {
        std::printf("%-10s%-5s%-5.2f%-10d\n",
        item.get_name().c_str(),
        code.c_str(),
        item.get_price(),
        item.get_stock());
    }
}
void ItemManager::checkout(const std::map<std::string, Item>& cartlist) {
    for(const auto& [code,item]:cartlist) {
        reduce_stock(item.get_code(),item.get_stock());
    }
    CSVwrite();
}