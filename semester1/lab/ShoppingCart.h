#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"
#include <vector>
using namespace std;

class ShoppingCart{
   private:
      string customerName;
      string currentDate;
      vector<ItemToPurchase> cartItems;
   public:
      ShoppingCart();
      ShoppingCart(string n, string d);

      string GetCustomerName();
      string GetDate();

      void AddItem(ItemToPurchase i);
      void RemoveItem(string n);
      void ModifyItem(ItemToPurchase i);

      int GetNumItemsInCart();
      int GetCostOfCart();

      void PrintTotal();
      void PrintDescriptions();
};

#endif
