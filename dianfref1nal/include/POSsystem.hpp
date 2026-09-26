#pragma once
#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include "SaleManager.hpp"
#include "ItemManager.hpp"
#include <string>

class POSsystem {
    private:
        SaleManager salemanager;
        ItemManager itemmanager;
        Cart cart;
        bool is_admin{false};

        void pos_scan(const std::string& code);          // 扫描/添加
        void pos_reduce(const std::string& code);        // 减少
        void pos_print();                                // 打印小票
        void pos_drop();                                 // 清空
        void pos_checkout();                             // 结账
        void pos_sales(int day);                         // 查看销售
        void pos_newday();                               // 新的一天

        void pos_admin(const std::string& line);         // 处理管理员命令
        void enter_admin();                              // 进入管理员
        void exit_admin();                               // 退出管理员

    public:
        void run();
};