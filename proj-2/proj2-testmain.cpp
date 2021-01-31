/**
-  file: proj2-testmain.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 02/01/2021
-
-  Date Modified: 01/30/2021
-    - File Created
*/
#include <iostream>
#include "proj2-arrayFunctions.h"

using namespace std;

void printArray(int *a, int);

int main(){
  int arr[8] = {7,8,7,5,4,-3,11,5};
  int *prr[8];
  for (int i = 0; i < 8; i++){
    prr[i] = arr + i;
  }

  printArray(*prr, 8);

  cout << largestValue(*prr, 8) << " "
       << smallestValue(*prr, 8) << " "
       << averageValue(*prr, 8) << " "
       << medianValue(*prr, 8) << endl;

  printArray(*prr, 8);

  cout << largestValue(*prr, 8) << " "
       << smallestValue(*prr, 8) << " "
       << averageValue(*prr, 8) << " "
       << medianValue(*prr, 8) << endl;

  return 0;
}

void printArray(int *a, int size){
  for (int i = 0; i < size; i++){
    cout << *(a + i) << " ";
  }
  cout << endl;
}
