#pragma once 
#include "Item.hpp"
#include <string>
#include <map>
class ItemManager {
    private:
        std::map<std::string, Item> items;      //内存总仓库
    public:
        void CSVwrite();
        void CSVread();

        void set_price(const std::string& code, double newprice);
        void add(const Item& item);
        void remove(const std::string& code);
        void set_stock(const std::string& code, int stock);
        void add_stock(const std::string& code, int delta);
        void reduce_stock(const std::string& code, int qty);

        void print() const;
        void checkout(const std::map<std::string, Item>& cartlist);
};