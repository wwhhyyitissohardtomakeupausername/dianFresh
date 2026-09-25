#include "SaleManager.hpp"
#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

void SaleManager::add_record(const Sale &sale) {
    daily_record.push_back(sale);
    std::ofstream out_put("data/sales.csv",std::ios::app);
    
}
void SaleManager::sales_check(int day) {
    
}
void SaleManager::new_day() {
    ;
}