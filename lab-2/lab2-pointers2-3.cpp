/**
-  file: pointers2-3.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 01/29/2021
-
-  Date Modified: 01/27/2021
-    - File Created
*/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char myArray[] = "Hello World!"; //not dynamically allocated
  char *myPtr = new char[13]; //dynamically allocated

  strcpy(myPtr, "Hello World!"); //the pointer now holds "Hello World!"

  cout << "This is from the array: " << myArray << endl; //both print the string
  cout << "This is from the pointer: " << myPtr << endl;// stored in the array
                                                       //  and the pointer
  cout << endl << "Let's try to change the array..." << endl;
  myArray[1] = 'o'; //array notation to change the value in the array
  myArray[2] = 'w';
  myArray[3] = 'd';
  myArray[4] = 'y';

  cout << "This is from the array: " << myArray << endl; //prints the string
                                                        // stored in the array
  cout << endl << "Let's try to change the pointer..." << endl;
  myPtr[1] = 'o'; //array notation to change the value in the pointer c string
  myPtr[2] = 'w';
  myPtr[3] = 'd';
  myPtr[4] = 'y';

  cout << "This is from the pointer: " << myPtr << endl;

  delete [] myPtr; //releases the allocated memory

  return 0;
}
