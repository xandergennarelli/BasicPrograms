/**
-  file: pointers2-2.cpp
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

char* giveMemory( ) {
  char* myArray = "Hello World!"; //does not actually dynamically allocate
  return myArray;
}

int main() {
  char *myPtr; //char array / string pointer

  myPtr = giveMemory();
  cout << myPtr << endl; //prints the contents of the char array

  myPtr[1] = 'o'; //error because the string literal "Hello World!" is constant
  myPtr[2] = 'w'; //  and cannot be changed in this way.
  myPtr[3] = 'd';
  myPtr[4] = 'y';

  cout << endl << myPtr << endl; //never runs

  return 0;
}
