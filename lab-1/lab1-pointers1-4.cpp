/**
-  file: pointers1-4.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 01/22/2021
-
-  Date Modified: 01/22/2021
-    - File Created
-
-  Pointer Introduction to indirection
*/
#include <iostream>

using namespace std;

int main() {
  int x, *intPtr;
  char ch, *charPtr;

  x = 10;
  intPtr = &x;

  ch = 'a';
  charPtr = &ch;

  cout << "The value of x is " << x << endl;
  cout << "The value of x using intPtr is " << *intPtr << endl;

  cout << "The value of ch is " << ch << endl;
  cout << "The value of ch using charPtr is " << *charPtr << endl;

  *intPtr = 0;
  *charPtr = 'Z';

  cout << "The value of x is " << x << endl;
  cout << "The value of ch is " << ch << endl;

  return 0;
}
