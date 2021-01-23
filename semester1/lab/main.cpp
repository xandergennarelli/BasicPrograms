#include "ShoppingCart.h"
using namespace std;

void PrintMenu(){
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
   cout << endl << "Choose an option:" << endl;
}

int main(){

   string name, date, description;
   int price, quantity;
   char opt;
   bool quit = false;
   cout << "Enter customer's name:" << endl;
   cin >> name;
   cout << "Enter today's date:" << endl;
   cin >> date;
   cout << endl << "Customer name: " << name;
   cout << endl << "Today's date: " << date << endl;
   ShoppingCart cart(name, date);

   while (!quit){
      PrintMenu();
      cin >> opt;
      switch (opt){
         case 'a':{
            ItemToPurchase a;
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            cin >> name;
            cout << "Enter the item description:" << endl;
            cin >> description;
            cout << "Enter the item price:" << endl;
            cin >> price;
            cout << "Enter the item quantity:" << endl;
            cin >> quantity;

            a.SetName(name);
            a.SetDescription(description);
            a.SetPrice(price);
            a.SetQuantity(quantity);
            cart.AddItem(a);
            break;}
         case 'd':{
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            cin >> name;
            cart.RemoveItem(name);
            break;}
         case 'c':{
            ItemToPurchase c;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            cin >> name;
            cout << "Enter the new quantity:" << endl;
            cin >> quantity;
            c.SetName(name);
            c.SetQuantity(quantity);
            cart.ModifyItem(c);
            break;}
         case 'i':{
            cout << "OUTPUT ITEM'S DESCRIPTIONS" << endl;
            cart.PrintDescriptions();
            break;}
         case 'o':{
            cout << "OUTPUT SHOPPING CART" << endl;
            cart.PrintTotal();
            break;}
         case 'q':
            quit = true;
            break;
      }
   if (opt == 'q') exit(1);
   }
}
