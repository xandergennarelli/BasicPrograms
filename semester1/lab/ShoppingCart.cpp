#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart(){
   customerName = "none";
   currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string n, string d){
   customerName = n;
   currentDate = d;
}

string ShoppingCart::GetCustomerName(){
   return customerName;
}
string ShoppingCart::GetDate(){
   return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase i){
   cartItems.push_back(i);
}
void ShoppingCart::RemoveItem(string n){
   bool erased = false;
      for (int i = 0; i < cartItems.size(); i++){
         if (cartItems.at(i).GetName() == n){
            cartItems.erase(cartItems.begin() + i);
            erased = true;
         }
      }
   if (!erased){
      cout << "Item not found in cart. Nothing removed." << endl;
   }
}
void ShoppingCart::ModifyItem(ItemToPurchase i){
   bool found = false;
   for (int j = 0; j < cartItems.size(); j++){
      if (cartItems.at(j).GetName() == i.GetName()){
         if (i.GetDescription() != "none"){
            cartItems.at(j).SetDescription(i.GetDescription());
         }
         if (i.GetPrice() != 0){
            cartItems.at(j).SetPrice(i.GetPrice());
         }
         if (i.GetQuantity() != 0){
            cartItems.at(j).SetQuantity(i.GetQuantity());
         }
         found = true;
      }
   }
   if (!found) cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart(){
   int sum = 0;
   for (int i = 0; i < cartItems.size(); i++){
      sum += cartItems.at(i).GetQuantity();
   }
   return sum;
}
int ShoppingCart::GetCostOfCart(){
  int sum = 0;
  for (int i = 0; i < cartItems.size(); i++){
     sum += cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice();
  }
  return sum;
}

void ShoppingCart::PrintTotal(){
   int sum = 0;
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
   for (int i = 0; i < cartItems.size(); i++){
      cartItems.at(i).PrintItemCost();
      sum += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
   }
   cout << endl << "Total: $" << sum << endl;
}
void ShoppingCart::PrintDescriptions(){
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << endl << "Item Descriptions" << endl;
   for (int i = 0; i < cartItems.size(); i++){
      cartItems.at(i).PrintItemDescription();
   }
}
