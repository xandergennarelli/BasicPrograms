/**
-  file: pointers1-5.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 01/22/2021
-
-  Date Modified: 01/22/2021
-    - File Created
-
-  Pointers as Parameters
*/
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

/**
-  changeIt
-
-  This function changes the value of the parameter passed to it using
-    pointers.
-
-  Parameters:
-    n: an address of variable declared locally in the calling function
-
-  Output:
-    return: none
-    parameters: n - the changed value at the address passed
-    stream: none
*/
void changeIt( int *n ){
  int r;

  r = rand() % 100;

  *n = r;
}

int main() {
   int x, y, z;

   x = y = z = 0;

   srand(time(0));

   cout << "x's value was " << x << " before a call to changeIt()" << endl;
   changeIt( &x );
   cout << "x's value is " << x << " after a call to changeIt()" << endl;

   cout << "y's value was " << y << " before a call to changeIt()" << endl;
   changeIt( &y );
   cout << "y's value is " << y << " after a call to changeIt()" << endl;

   cout << "z's value was " << z << " before a call to changeIt()" << endl;
   changeIt( &z );
   cout << "z's value is " << z << " after a call to changeIt()" << endl;

   return 0;
}
