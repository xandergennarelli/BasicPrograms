/**
-  file: pointers1-2.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 01/22/2021
-
-  Date Modified: 01/22/2021
-    - File Created
-
-  Pointer as a variable
*/
#include <iostream>

using namespace std;

int main() {

double dbl, dbl2;
double *dblPtr;

dbl = 2.5;
dblPtr = &dbl;

cout << dbl << endl;
cout << dblPtr << endl;
cout << &dbl << endl;
cout << &dblPtr << endl;
cout << sizeof(dbl) << endl;
cout << sizeof(dblPtr) << endl;

dblPtr = &dbl2;
cout << dbl2 << endl;
cout << dblPtr << endl;
cout << &dbl2 << endl;
cout << &dblPtr << endl;

return 0;
}
