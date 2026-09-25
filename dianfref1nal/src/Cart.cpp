#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include "SaleManager.hpp"
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
void Cart::add_item(const Item &add_it) {     //直接只读Item进来
    const std::string& code=add_it.get_code();
    double price=add_it.get_price();
    this->cart[code].set_stock(this->cart[code].get_stock()+1);
    this->cart[code].set_price(price);
    this->cart[code].set_code(code);
    this->cart[code].set_name(add_it.get_name());
    total+=price;
}
void Cart::rdc_item(const Item &rdc_it) {
    const std::string& code=rdc_it.get_code();
    this->cart[code].set_stock(this->cart[code].get_stock()-1);
    if(!this->cart[code].get_stock()) {
        cart.erase(code);
    }
    total-=rdc_it.get_price();
}
void Cart::print_receipt()const {
    std::cout<<"Receipt\n";
    printf("%-10s%-10s%-10s%-10s\n","Item","Pri.","Qty","Amount");
    for(int i=0;i<=45;++i) {std::cout<<'-';}
    std::cout<<'\n';
    for(const auto& p:cart) {
        double pri=p.second.get_price();
        // std::cout<<"Successfully get_price"<<pri<<std::endl;
        int sto=p.second.get_stock();
        // std::cout<<"Successfully getget_stock"<<sto<<std::endl;
        const std::string& name=p.second.get_name();
        // std::cout<<"Successfully get_name"<<name<<std::endl;

        char sSto[32];
        char sAmo[32];

        std::snprintf(sSto,sizeof(sSto),"x%d",sto); //int snprintf(char *__stream, size_t/*unsigned int的别名*/ __n, const char *__format, ...)
        std::snprintf(sAmo,sizeof(sAmo),"=%.2f",pri*sto);

        printf("%-10s%-10.2f%-10s%-10s\n",
            name.c_str(),pri,sSto,sAmo);
    }
    for(int i=0;i<=45;++i) {std::cout<<'-';}
    std::cout<<'\n';
    char sTot[32];
    std::snprintf(sTot,sizeof(sTot),"=%.2f",total);
    printf("%-10s%10s\n","Total",sTot);
}
Sale Cart::checkout() {
    print_receipt();
    Sale sale(cart,total);
    drop();
    return sale;
}