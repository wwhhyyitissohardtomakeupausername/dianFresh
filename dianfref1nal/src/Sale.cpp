#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
Sale::Sale(std::map<std::string,Item> one_sale,double total) {
    this->one_sale=one_sale;
    this->total=total;
}