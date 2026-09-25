#pragma once
#include "Item.hpp"
#include "Sale.hpp"
#include <string>
#include <map>
class Cart{
    private:
        std::map<std::string,Item> cart;
        double total{0};        //实时维护价格
    public:
        void add_item(const Item &add_it);      //添加物品
        void rdc_item(const Item &rdc_it);      //减少物品
        void print_receipt()const;      //打印收据
        void drop(){cart.clear();total=0;}      //清空购物车并价格归零
        Sale checkout();
};