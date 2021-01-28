/**
-  file: pointers2-1.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 01/29/2021
-
-  Date Modified: 01/27/2021
-    - File Created
*/
#include <iostream>

using namespace std;

int main() {
  char myArray[] = "Hello World!"; //storing "Hello World!" in array
  char *myPtr = "Hello World!"; //storing "Hello World!" in as pointer / c string

  cout << "This is from the array: " << myArray << endl; //prints the array contents
  cout << "This is from the pointer: " << myPtr << endl; //also prints array contents
  cout << endl;

  cout << "Trying to move the array ..." << endl;
  myArray += 6; //throws error because the address of myArray cannot be changed directly
  cout << "This is from the array: " << myArray << endl; //does not get run
  return 0;
}
