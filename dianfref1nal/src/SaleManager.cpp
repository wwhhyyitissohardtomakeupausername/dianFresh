#include "SaleManager.hpp"
#include "Item.hpp"
#include "Sale.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <map>
namespace {     //匿名命名空间
    void ofile_print(const Sale& sale) {     //文件输出流水函数
        std::ofstream out_put("data/sales.csv",std::ios::app);
        //Date,No,Time,Items,Ament
        out_put<<sale.get_date()<<','<<sale.get_id()<<','<<sale.get_time()<<',';
        bool tmpflag=true;      //临时用于判断是否为第一个物品项
        for(const auto& [the_code,the_item] : sale.get_items()) {
            if(tmpflag) tmpflag=false;      //补分号策略,下面打印流水也用了相似的操作
            else out_put<<';';

            out_put<<the_item.get_name()<<':'
            <<the_item.get_stock()<<':'
            <<the_item.get_code()<<':'
            <<the_item.get_price();
        }
        out_put<<','<<sale.get_total()<<'\n';
    }
    void Sale_print(const Sale& sale) {
        printf("%5d%10s",sale.get_id(),sale.get_time().c_str());     //第一次要输出流水号和时间
        bool check_start=true;
        for(const auto& [the_code,the_item]:sale.get_items()) {
            //遍历sale.getitems()
            if(check_start) {check_start=false;}
            else {printf("\n               ");}       //补换行,维持格式
            char sNameAndCount[32];
            std::snprintf(sNameAndCount,
            sizeof(sNameAndCount),
            "%sx%d",
            the_item.get_name().c_str(),
            the_item.get_stock());      //超级拼装    
            printf("%15s",sNameAndCount);       //按格式输出名称和数量
        }
        printf("%10.2f\n",sale.get_total());       //输出一次总和
    }
    Sale CSVtransform(const std::string& Date,
    const std::string& No,
    const std::string& Time,
    const std::string& Items,
    const std::string& Ament) {
        std::map<std::string, Item> item_map;
        // Items 形如: name:stock:code:price;name:stock:code:price;...
        std::istringstream item_stream(Items);
        std::string one_item;
        while (std::getline(item_stream, one_item, ';')) {
            if (one_item.empty()) continue;   // 末尾可能多一个分号
        
            std::istringstream field(one_item);
            std::string name, stock_str, code, price_str;
            std::getline(field, name,      ':');
            std::getline(field, stock_str, ':');
            std::getline(field, code,      ':');
            std::getline(field, price_str, ':');
            
            // std::cerr<<"start stoiStock_str"<<stock_str<<"\n";
            item_map[code] = Item(name, code, std::stod(price_str), std::stoi(stock_str));
        }

        Sale sale=Sale();
        sale.set_items(item_map);
        sale.set_total(std::stod(Ament));
        // std::cerr<<"start stoiDate\n";
        sale.set_date(std::stoi(Date));
        // std::cerr<<"finish stoiDate\n";
        // std::cerr<<"start stoiNo\n";
        sale.set_id(std::stoi(No));
        // std::cerr<<"finish stoiNo\n";
        sale.set_time(Time);

        return sale;
    }
}
void SaleManager::add_record(Sale sale) {       //1.追加写入文件
    //加入今日流水并更新流水号
    sale.set_date(current_day);
    sale.set_id(id_next);       //id_next还没更新
    daily_record.push_back(sale);
    //更新文件记录
    ofile_print(sale);
    id_next++;      //这样让sale_id和daily_record的下标保持一致
}
void SaleManager::sales_check(int day) {        //2.查看当日所有销售记录及总营业额，省略 day 参数默认为今天
    //输出表头
    printf("Date:%d\n%5s%10s%15s%10s\n"
        ,day,"No.","Time","Items","Ament");
    for(int i=0;i<=40;i++) printf("-");
    printf("\n");

    //中间部位
    double daily_total{0};
    if(day==current_day) {       //如果就是当天,直接daily_record
        for(int i=1;i<daily_record.size();i++) {        //遍历该天记录
            daily_total+=daily_record[i].get_total();       //维护一日总和
            Sale_print(daily_record[i]);
        }
    } else {
        std::ifstream in_put("data/sales.csv");
        std::string current_line{};
        while(std::getline(in_put,current_line)) {
            std::istringstream iss(current_line);
            std::string Date;
            std::getline(iss,Date,',');
            // std::cerr<<"Date:"<<Date<<'\n';
            if(std::stoi(Date) != day) continue;      //如果不是就往下找
            //开读
            std::string No,Time,Items,Ament;
            std::getline(iss,No,',');
            std::getline(iss,Time,',');
            std::getline(iss,Items,',');
            std::getline(iss,Ament,',');
            Sale sale=CSVtransform(Date,No,Time,Items,Ament);
            Sale_print(sale);
            daily_total+=std::stod(Ament);
        }
    }
    //输出表尾
    for(int i=0;i<=40;i++) std::cout<<'-';
    printf("\nDaily:%.2f\n",daily_total);
}
void SaleManager::new_day() {
    daily_record.clear();
    daily_record.push_back(Sale());
    current_day++;
    id_next=1;
}