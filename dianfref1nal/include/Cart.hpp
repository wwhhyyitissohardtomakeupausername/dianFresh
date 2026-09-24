#pragma once
#include "Item.hpp"
#include <string>
#include <map>
class Cart{
    private:
        std::map<std::string,Item> cart;
    public:
        void add_item(std::string code);
        void rdc_item(std::string code);
        void print_receipt()const;
        void drop();
        void checkout();
};