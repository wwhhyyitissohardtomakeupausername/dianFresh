#pragma once
#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include <vector>
class SaleManager{      //一天的流水
    private:
        std::vector<Sale> daily_record{1};      //每一个都是一次流水,占位(有隐式转换),下标(和id同步)都从一开始
        int id_next{1},       //动态维护,今天的流水号排到哪里了
        current_day{1};     //现在到第几天了
    public:
        void set_date(int day) {current_day=day;}
        void add_record(Sale sale);      //1.追加写入文件
        void sales_check(int that_day);      //2.查看当日所有销售记录及总营业额，省略 day 参数默认为今天
        void sales_check(){sales_check(current_day);}
        void new_day();     //3.开始新的一天：清空当日销售记录
        void init(); // 启动时从文件恢复状态
};