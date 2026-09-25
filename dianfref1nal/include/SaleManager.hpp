#pragma once
#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include <vector>
class SaleManager{
    private:
        std::vector<Sale> daily_record;
        int day=1,sale_id=1;
    public:
        void add_record(const Sale &sale);      //1.追加写入文件
        void sales_check(int day);      //2.查看当日所有销售记录及总营业额，省略 day 参数默认为今天
        void sales_check(){sales_check(this->day);}
        void new_day();     ////3.开始新的一天：清空当日销售记录
};