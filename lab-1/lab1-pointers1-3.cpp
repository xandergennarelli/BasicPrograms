/**
-  file: pointers1-3.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 01/22/2021
-
-  Date Modified: 01/22/2021
-    - File Created
-
-  Pointer Arithmetic
*/
#include <iostream>

using namespace std;

int main() {
	int x, *intPtr = &x;
	char ch, *chPtr = &ch;
	double dbl, *dblPtr = &dbl;

	cout << intPtr << " is the initial value of intPtr" << endl;
	cout << (int*)chPtr << " is the initial value of chPtr" << endl;
	cout << dblPtr << " is the initial value of dblPtr" << endl;

	intPtr++;
	chPtr++;
	dblPtr++;

	cout << intPtr << " is the new value of intPtr" << endl;
	cout << (int*)chPtr << " is the new value of chPtr" << endl;
	cout << dblPtr << " is the new value of dblPtr" << endl;

	return 0;
}
