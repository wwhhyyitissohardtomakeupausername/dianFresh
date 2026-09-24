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
        std::string getname()const {return name;}       //简单功能直接在hpp里面实现
        std::string getcode()const {return code;}
        double getprice()const {return price;}
        int getstock()const {return stock;}

        void setname(std::string newname) {name=newname;}
        void setcode(std::string newcode) {code=newcode;}
        void setstock(int newstock) {stock=newstock;}
        void setprice(double newprice) {price=newprice;}
};