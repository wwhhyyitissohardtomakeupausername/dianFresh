#include "Item.hpp"
#include "Cart.hpp"
#include "Sale.hpp"
#include "SaleManager.hpp"
#include "ItemManager.hpp"
class POSsystem{
    private:
        SaleManager salemanager;
        ItemManager itemmanager;
        Cart cart;

        void pos_scan();
        void pos_checkout();
        void pos_sales();
        void pos_admin();
    public:
        void run();
};