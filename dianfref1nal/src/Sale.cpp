#include "Item.hpp"
#include "Sale.hpp"
#include <iomanip>
#include <sstream>
#include <ctime>
#include <map>
Sale::Sale(std::map<std::string,Item> one_sale,double total) {
    this->one_sale=one_sale;
    this->total=total;
    std::time_t now = std::time(nullptr);
    std::tm* ptm = std::localtime(&now);
    std::tm tm = *ptm;
    std::ostringstream time_stream;
    time_stream << std::put_time(&tm, "%H:%M:%S");
    this->time = time_stream.str();
}