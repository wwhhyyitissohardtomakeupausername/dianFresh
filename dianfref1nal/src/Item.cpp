#include "Item.hpp"
#include <iostream>
#include <string>
Item::Item(std::string name0,
    std::string code0,
    double price0,
    int stock0) {
    name=name0;
    code=code0;
    price=price0;
    stock=stock0;
    // std::cout<<"\nname:"<<name;
    // std::cout<<"\ncode:"<<code;
    // std::cout<<"\nprice:"<<price;
    // std::cout<<"\nstock:"<<stock;
}       //初始化物品信息