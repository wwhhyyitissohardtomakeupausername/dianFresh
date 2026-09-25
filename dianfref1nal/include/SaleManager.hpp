#pragma once
#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include <vector>
class SaleManager{      //一天的流水
    private:
        std::vector<Sale> daily_record;
        int id_next{0},       //动态维护,今天的流水号排到哪里了
        day{0};     //最新到第几天了
    public:
        void set_date(int day) {this->day=day;}
        void renew_record(Sale sale);      //1.追加写入文件
        void sales_check(int day);      //2.查看当日所有销售记录及总营业额，省略 day 参数默认为今天
        void sales_check(){sales_check(this->day);}
        void new_day();     //3.开始新的一天：清空当日销售记录
};