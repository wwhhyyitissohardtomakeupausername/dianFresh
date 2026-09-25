#pragma once
#include "Item.hpp"
#include <map>
class Sale{     //传入账单,提供其他交易信息
    private:
        std::map<std::string,Item> one_sale;
        double total{0.0};
        std::string time{};
        int day{0},sale_id{0};
    public:
        Sale(std::map<std::string,Item> one_sale,double total);
        //在Cart.checkout中调用时构造,此时时间 id date未知
        void set_date(int date){this->day=date;}
        void set_id(int id){this->sale_id=id;}
        //露两个接口,方便SaleManager操作
        const std::map<std::string,Item>&get_items()const{ return one_sale; }
        double get_total() const { return total; }
        const std::string& get_time() const { return time; }
        int get_date()const{return this->day;}
        int get_id()const{return this->sale_id;}
        //获取信息
};