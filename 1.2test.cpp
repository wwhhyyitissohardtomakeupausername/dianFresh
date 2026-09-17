#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
/*
1.2 订单结账
店员可以输入多个商品 ，需要记录这些商品的数量 ，然后完成结账功能。顾客有时会不想要某些商品 ，还需要删除这些商品。你需要设计合适的终端输出 ，使得结果便于查看。
完成以下指令：
•   <id> 输入条码 ，记录对应商品+1 ，显⽰价格
•   -<id> 在输入前添加一个  减号 ，记录对应商品-1
•   print 打印现在的小票 ，包含商品种类、数量与价格 ，以及小计价格
•   drop 清空记录 ，重新开始
•   checkout 结账。打印小票并清空记录。
*/
struct Item {       //一类物品
    string Code;        //条码
    string Name;        //商品名
    string Price;       //价格
    int Quantity=0;       //数量
};
vector<Item> itemList,cart;       //物品列表,购物车

int findIt(vector<Item> &List, string itemcode) {     //查找条码对应的物品或商品的下标,返回0表示未找到
    for(int i=1;i<List.size();i++) {
        if( List[i].Code==itemcode) return i;
    }
    return 0;
}
void PrintCart() {
    for(int i=1;i<cart.size();i++) {
        printf("%-15s%sx%s  =%.2f\n",
            cart[i].Name.c_str(),
            cart[i].Price.c_str(),
            to_string(cart[i].Quantity).c_str(),
            stod(cart[i].Price) * cart[i].Quantity);
    }
}
void EnterC(string str,string tmp) {     //1.2输入条码,加入购物车中,输出名称和费用计算(单价*数量=这一项的总和),如果条码前加负号,则表示从购物车中删除该商品
    istringstream iss(str);
    while(iss >> tmp) {
        int flag=1;
        if(tmp[0]=='-') tmp=tmp.substr(1),flag=-1;       //如果条码前加负号,则表示从购物车中删除该商品
        int indi=findIt(itemList, tmp)*flag,indc=findIt(cart, tmp);
        if(indi>0 && indi<=itemList.size()-1) {       //从1开始,0是空物品,如果仓库有该物品
            if(indc==0)     //购物车中没有该商品,就添加该商品到购物车
                cart.push_back({itemList[indi].Code,itemList[indi].Name,itemList[indi].Price,1});
            else        //购物车中有该商品,就数量+1
                cart[indc].Quantity++;
        } else if(indi<0 && -indi<=cart.size()-1) {       //把负号消除,从1开始,0是空物品
            if(indc>0) {       //购物车中有该商品
                cart[indc].Quantity--;//购物车中有该商品，就使数量减一
                if(cart[indc].Quantity==0) cart.erase(cart.begin()+indc);     //数量为0,删除该商品
            }
        } else printf("ERROR: code not found\n");
    }
    PrintCart();        //我觉得可以同时加减物品好一些……
}
void EnterR() {     //1.2打印购物车中所有商品的名称和价格(单价*数量=这一项的总和)receipt,并计算总价
    printf("Receipt\n");
    printf("%-15s%s %s %s\n","Item","Pri.","Qty","Amount");;
    printf("-------------------------\n");
    PrintCart();
    double total=0.0;
    for(int i=1;i<cart.size();i++) total+=stod(cart[i].Price) * cart[i].Quantity;
    printf("-------------------------\n");
    printf("Total: %.2f\n",total);
}
void Enter1_2() {      //1.2完整要求实现
    while(true) {
        string str,tmp;
        getline(cin, str);
        istringstream iss(str);
        iss >> tmp;     //读取第一个单词
        if(tmp=="checkout") {
            EnterR();
            cart.erase(cart.begin()+1,cart.end());
        }
        else if(tmp=="drop") cart.erase(cart.begin()+1,cart.end());
        else if(tmp=="print") EnterR();
        else if(tmp=="exit") return;
        else {
            iss.clear();        //清除录入的商品代码
            iss.str(str);       //重新设置输入流
            EnterC(str, tmp);
        }
    }
}
int main() {        //初始化物品列表,输入1.2进入购物车模式,否则退出程序
    itemList.push_back({"000","NULL","0.00",0});
    itemList.push_back({"001","Cola","3.50",100});
    itemList.push_back({"002","Lollipop","0.50",200});
    itemList.push_back({"003","Noodles","6.00",50});
    cart.push_back({"000","NULL","0.00",0});
    string com;
    while(true) {
        printf("Please enter the command:\n");
        cin>>com;
        if(com=="1.2") {
            cin.ignore(10000,'\n');
            Enter1_2();
        } else return 0;
    }
    return 0;
}