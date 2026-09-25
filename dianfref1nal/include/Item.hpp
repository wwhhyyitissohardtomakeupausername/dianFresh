#pragma once
#include <string>
class Item{     //只是做一个接口,体现一下封装思想
    private:
        std::string name{},code{};
        double price=0.0;
        int stock=0;
    public:
        Item()=default;
        Item(const std::string &name0,const std::string &code0,
        double price0,int stock0);
        std::string get_name()const {return name;}       //简单功能直接在hpp里面实现
        std::string get_code()const {return code;}
        double get_price()const {return price;}
        int get_stock()const {return stock;}

        void set_name(const std::string &new_name) {name=new_name;}
        void set_code(const std::string &new_code) {code=new_code;}
        void set_stock(int new_stock) {stock=new_stock;}
        void set_price(double new_price) {price=new_price;}
};