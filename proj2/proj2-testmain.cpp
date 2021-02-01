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
#include <cassert>
#include "proj2-arrayFunctions.h"

using namespace std;

void printArray(int *ptrs, int);
void fillArray(int *ptrs, int arr[], int);

const int SIZE_1 = 8, SIZE_2 = 12, SIZE_3 = 3, SIZE_4 = 1, SIZE_5 = 4;
int main(){
  int *prr1, *prr2, *prr3, *prr4, *prr5;  //setup all starting values
  int arr1[SIZE_1] = {7,8,7,5,4,-3,11,5};
  prr1 = new int[SIZE_1];
  fillArray(prr1, arr1, SIZE_1);
  int arr2[SIZE_2+4] = {-7,-5,-8,-11,-0,-1,-99,-8,-100,-77,-46,-4,10,5,-999,40};
  prr2 = new int[SIZE_2+4];     //testing that functions stay within given size
  fillArray(prr2, arr2, SIZE_2+4);
  int arr3[SIZE_3] = {2147483647, 99999999, -99999999};
  prr3 = new int[SIZE_3];
  fillArray(prr3, arr3, SIZE_3);
  int arr4[SIZE_4] = {0};
  prr4 = new int[SIZE_4];
  fillArray(prr4, arr4, SIZE_4);
  int arr5[SIZE_5] = {2,2,2,2};
  prr5 = new int[SIZE_5];
  fillArray(prr5, arr5, SIZE_5);

  cout << "initial arrays::" << endl;
  printArray(prr1, SIZE_1);
  printArray(prr2, SIZE_2);
  printArray(prr3, SIZE_3);
  printArray(prr4, SIZE_4);
  printArray(prr5, SIZE_5);
  cout << endl;

  assert((largestValue(prr1, SIZE_1) == 11));
  assert((largestValue(prr2, SIZE_2) == -0));
  assert((largestValue(prr3, SIZE_3) == 2147483647));
  assert((largestValue(prr4, SIZE_4) == 0));
  assert((largestValue(prr5, SIZE_5) == 2));
  cout << "largestValue good." << endl;

  assert((smallestValue(prr1, SIZE_1) == -3));
  assert((smallestValue(prr2, SIZE_2) == -100));
  assert((smallestValue(prr3, SIZE_3) == -99999999));
  assert((smallestValue(prr4, SIZE_4) == 0));
  assert((smallestValue(prr5, SIZE_5) == 2));
  cout << "smallestValue good." << endl;

  assert((averageValue(prr1, SIZE_1) == 5.5));
  assert((averageValue(prr2, SIZE_2) == -30.5));
  assert((averageValue(prr3, SIZE_3) == 715827882.3333334));
  assert((averageValue(prr4, SIZE_4) == 0));
  assert((averageValue(prr5, SIZE_5) == 2));
  cout << "averageValue good." << endl;

  assert((medianValue(prr1, SIZE_1) == 5));     // uses both medianValue
  assert((medianValue(prr2, SIZE_2) == -8));   //  and bubble sort.
  assert((medianValue(prr3, SIZE_3) == 99999999));
  assert((medianValue(prr4, SIZE_4) == 0));
  assert((medianValue(prr5, SIZE_5) == 2));
  cout << "medianValue good." << endl;

  cout << endl << "sorted arrays::" << endl;
  printArray(prr1, SIZE_1);
  printArray(prr2, SIZE_2);
  printArray(prr3, SIZE_3);
  printArray(prr4, SIZE_4);
  printArray(prr5, SIZE_5);

  delete prr1;
  delete prr2;
  delete prr3;
  delete prr4;
  delete prr5;
  return 0;
}

/*
* printArray
*
* This function prints a given pointer array to the screen.
*
* Parameters:
*     ptrs: the array of pointers to be printed
*     size: the number of pointers in the array
*
* Output:
*     return: none
*     reference parameters: ptrs, unchanged
*     streams: none
*/
void printArray(int *ptrs, int size){
  for (int i = 0; i < size; i++){
    cout << *(ptrs + i) << " ";
  }
  cout << endl;
}

/*
* fillArray
*
* This function prints a given pointer array to the screen.
*
* Parameters:
*     ptrs: the array of pointers to be assigned
*     arr: an int arr that should be pointed to by ptrs
*     size: the number of pointers in the array
*
* Output:
*     return: none
*     reference parameters: ptrs, now populated
*     streams: none
*/
void fillArray(int *ptrs, int arr[], int size){
  for (int i = 0; i < size; i++){
    *(ptrs + i) = arr[i];
  }
}
