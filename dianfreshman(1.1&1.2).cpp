#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
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

void EnterP(string str,string tmp) {     //1.1输入条码，输出名称和价格
    istringstream iss(str);
    while(iss >> tmp) {
        int ind=findIt(itemList, tmp);
        if(ind>0 && ind<=itemList.size()-1) {       //从1开始,0是空物品
            printf("%-15s%5s\n",itemList[ind].Name.c_str(),itemList[ind].Price.c_str());
        } else {
            printf("ERROR: code not found\n");
        }
    }
}
void EnterAll() {     //1.1输入prices输出名称、条码和价格
    printf("%-15s%5s%5s\n","Item","No.","Pri.");
    printf("-------------------------\n");
    for(int i=1;i<=itemList.size()-1;i++)       //从1开始,0是空物品
        printf("%-15s%5s%5s\n",itemList[i].Name.c_str(),itemList[i].Code.c_str(),itemList[i].Price.c_str());
}
void Enter1_1() {      //1.1完整要求实现
    while(true) {
        string str,tmp;
        getline(cin, str);
        istringstream iss(str);
        iss >> tmp;
        if(tmp=="prices") {
            EnterAll();
        } else if(tmp=="exit") {
            return;
        } else {
            iss.clear();        //清除录入的商品代码
            iss.str(str);       //重新设置输入流
            EnterP(str, tmp);
        }
    }
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

void Enter1_3() {       //1.3完整要求实现
    while(true) {
        string str,tmp;
        getline(cin, str);
        istringstream iss(str);
        iss >> tmp;
        if(tmp=="exit") return;
    }

}

int main() {
    itemList.push_back({"000","NULL","0.00",0});
    itemList.push_back({"001","Cola","3.50",100});
    itemList.push_back({"002","Lollipop","0.50",200});
    itemList.push_back({"003","Noodles","6.00",50});
    string com;
    while(true) {
        printf("Please enter the command:\n");
        cin>>com;
        if(com=="1.1") {
            cin.ignore(10000,'\n');
            Enter1_1();
        } else if(com=="1.2") {
            cin.ignore(10000,'\n');
            Enter1_2();
        } else if(com=="1.3") {
            cin.ignore(10000,'\n');
            Enter1_3();
        } else if(com=="exit") return 0;
        else {
            printf("ERROR: command not found\n");
            cin.ignore(10000,'\n');
        }
    }
    return 0;
}