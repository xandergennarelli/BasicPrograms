#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
#include <iostream>
using namespace std;

class ItemToPurchase{
   private:
      string itemName, itemDescription;
      int itemPrice, itemQuantity;
   public:
      ItemToPurchase();
      ItemToPurchase(string n, string d, int p, int q);
      void SetName(string n);
      void SetDescription(string d);
      void SetPrice(int);
      void SetQuantity(int);

      string GetName();
      string GetDescription();
      int GetPrice();
      int GetQuantity();

      void PrintItemCost();
      void PrintItemDescription();
};

#endif
