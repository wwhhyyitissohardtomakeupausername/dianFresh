#pragma once
#include <string>
class Item{
    private:
        std::string name{},code{};
        double price=0.0;
        int stock=0;
    public:
        Item()=default;
        Item(std::string name0,std::string code0,
        double price0,int stock0);
        std::string getname()const;
        std::string getcode()const;
        double getprice()const;
        int getstock()const;
        void setstock(int newstock);
        void setprice(double newprice);
};