#include "Item.hpp"
#include "Cart.hpp"
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
void Cart::add_item(std::string code) {
    this->cart[code].setstock(this->cart[code].getstock()+1);
}
void Cart::rdc_item(std::string code) {
    this->cart[code].setstock(this->cart[code].getstock()-1);
    if(!this->cart[code].getstock()) {
        cart.erase(code);
    }
}
void Cart::print_receipt()const {
    double total=0;
    std::cout<<"Receipt\n";
    printf("%-10s%-10s%-10s%-10s\n","Item","Pri.","Qty","Amount");
    for(int i=0;i<=45;++i) {std::cout<<'-';}
    std::cout<<'\n';
    for(const auto& p:cart) {
        double pri=p.second.getprice();
        int sto=p.second.getstock();
        std::string name=p.second.getname();
        total+=pri*sto;

        char sSto[32];
        char sAmo[32];

        std::snprintf(sSto,sizeof(sSto),"x%d",sto);
        std::snprintf(sAmo,sizeof(sAmo),"=%.2f",pri*sto);

        printf("%-10s%-10.2f%-10s%-10s",
            name.c_str(),pri,sSto,sAmo);
    }
    for(int i=0;i<=45;++i) {std::cout<<'-';}
    std::cout<<'\n';
    char sTot[32];
    std::snprintf(sTot,sizeof(sTot),"=%.2f",total);
    printf("%-10s%10s","Total",sTot);
}
void Cart::drop() {
    cart.clear();
}
void Cart::checkout() {
    print_receipt();
    drop();
}