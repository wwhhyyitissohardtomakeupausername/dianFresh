#include "Item.hpp"
#include <string>
Item::Item(std::string name0,
    std::string code0,
    double price0,
    int stock0) {
    name=name0;
    code=code0;
    price=price0;
    stock=stock0;
}       //初始化物品信息