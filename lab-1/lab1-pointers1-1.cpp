/**
-  file: pointers1-1.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 01/22/2021
-
-  Date Modified: 01/22/2021
-    - File Created
-
-  The Reference Operator
*/
#include <iostream>

using namespace std;

int main() {
    int x;
    int *intPtr;
    char ch;
    char *chPtr;

    x = 10;
    intPtr = &x;

    cout << "x's value is " << x << endl;
    cout << "intPtr's value is " << intPtr << endl;

    cout << "x's address is " << &x << endl;

    cout << "The size of x is " << sizeof(x) << endl;
    cout << "The size of intPtr is " << sizeof(intPtr) << endl;


    ch = 'a';
    chPtr = &ch;

    cout << "ch's value is " << ch << endl;
    cout << "chPtr's value is " << (int*) chPtr << endl;

    cout << "ch's address is " << (int*) &ch << endl;

    cout << "The size of ch is " << sizeof(ch) << endl;
    cout << "The size of chPtr is " << sizeof(chPtr) << endl;

    return 0;
}
