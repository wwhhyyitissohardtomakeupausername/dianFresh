#include "SaleManager.hpp"
#include "Item.hpp"
#include "Sale.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
namespace {     //匿名命名空间
    void standard_print(int day,int id,const std::string& time,double total,const Item& the_item) {
        std::ofstream out_put("data/sales.csv",std::ios::app);
        out_put<<day<<','<<id<<','<<time<<','
        <<the_item.get_name()<<'x'<<the_item.get_stock()<<','<<total<<'\n';
    }
}
void SaleManager::renew_record(Sale sale) {
    //加入今日流水并更新流水号
    sale.set_date(day);
    sale.set_id(id_next);       //id_next还没更新
    daily_record.push_back(sale);
    id_next++;      //这样让sale_id和daily_record的下标保持一致
    //更新文件记录
    for(const auto& [the_code,the_item] : sale.get_items()){
            standard_print(day,id_next-1,sale.get_time(),sale.get_total(),the_item);
    }
}
void SaleManager::sales_check(int day) {
    
}
void SaleManager::new_day() {
    
}