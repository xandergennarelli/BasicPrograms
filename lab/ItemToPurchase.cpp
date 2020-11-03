#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase(){
   itemName = "none";
   itemDescription = "none";
   itemPrice = 0;
   itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string n, string d, int p, int q){
   itemName = n;
   itemDescription = d;
   itemPrice = p;
   itemQuantity = q;
}

void ItemToPurchase::SetName(string n){
   itemName = n;
}
void ItemToPurchase::SetDescription(string d){
   itemDescription = d;
}
void ItemToPurchase::SetPrice(int p){
   itemPrice = p;
}
void ItemToPurchase::SetQuantity(int q){
   itemQuantity = q;
}

string ItemToPurchase::GetName(){
   return itemName;
}
string ItemToPurchase::GetDescription(){
   return itemDescription;
}
int ItemToPurchase::GetPrice(){
   return itemPrice;
}
int ItemToPurchase::GetQuantity(){
   return itemQuantity;
}

void ItemToPurchase::PrintItemCost(){
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << (itemQuantity * itemPrice) << endl;
}
void ItemToPurchase::PrintItemDescription(){
   cout << itemName << ": " << itemDescription << endl;
}
