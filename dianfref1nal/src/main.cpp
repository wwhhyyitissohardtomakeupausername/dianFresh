#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include "Item.hpp"
#include "Cart.hpp"
std::map<std::string,Item> items;
Cart cart;
int main() {
    items["001"]=Item("Cola","001",4.00,70);
    items["002"]=Item("Lollipop","002",0.50,80);
    items["003"]=Item("Noodles","003",6.00,20);
    while(true) {
        std::string str,tmp;
        std::getline(std::cin, str);
        std::istringstream iss(str);
        iss >> tmp;     //读取第一个单词
        if(tmp=="checkout") {
            cart.checkout();
        }
        else if(tmp=="drop") cart.drop();
        else if(tmp=="print") cart.print_receipt();
        else if(tmp=="exit") return 0;
        else {
            iss.clear();        //清除录入的商品代码
            iss.str(str);       //重新设置输入流
            std::istringstream iss(str);
            while(iss >> tmp) {
                if(tmp[0]=='-') {
                    tmp=tmp.substr(1);
                    cart.rdc_item(items[tmp]);
                }
                else{
                    cart.add_item(items[tmp]);
                }
            }
        }
    }
}