#pragma once
#include "Item.hpp"
#include <string>
#include <map>
class Cart{
    private:
        std::map<std::string,Item> cart;
    public:
        void add_item(const Item &addit);
        void rdc_item(const Item &rdcif);
        void print_receipt()const;
        void drop();
        void checkout();
};