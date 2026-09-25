#pragma once
#include "Item.hpp"
#include "Cart.hpp"
class Sale{
    private:        //其实和Cart一样,只是做个封装和检查
        std::map<std::string,Item> one_sale;
        double total;
    public:
        Sale(std::map<std::string,Item> one_sale,double total);
};