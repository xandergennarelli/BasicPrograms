/**
-  file: pointers2-4.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 01/29/2021
-
-  Date Modified: 01/27/2021
-    - File Created
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  string *str = new string("Hello World!"); //dynamically allocates memory to string

  // using the indirection operator to access the public interface of string
  cout << (*str).length() << endl;

  // using the structure pointer operator to access the public interface of string
  cout << str->length() << endl;

  cout << (*str).c_str() << endl; //using indirection operator to print str

  cout << str->c_str() << endl; //using structure pointer operator to print str

  delete str; //releases dynamically allocated memory

  return 0;
}
