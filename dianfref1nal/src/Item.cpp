#include "Item.hpp"
#include <string>
Item::Item(std::string name0,std::string code0,double price0,int stock0) {
    name=name0;code=code0;price=price0;stock=stock0;
}
std::string Item::getname()const {return name;}
std::string Item::getcode()const {return code;}
double Item::getprice()const {return price;}
int Item::getstock()const {return stock;}
void Item::setstock(int newstock) {stock=newstock;}
void Item::setprice(double newprice) {price=newprice;}