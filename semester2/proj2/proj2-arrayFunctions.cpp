/**
-  file: proj2-arrayFunctions.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 02/01/2021
-
-  Date Modified: 01/29/2021
-    - File Created
-  Date Modified: 01/30/2021
-    - Implemented functions
*/
#include <algorithm>
#include "proj2-arrayFunctions.h"

using namespace std;

/*
* bubbleSort
*
* This function sorts a given array of pointers of a given size.
*
* Parameters:
*     array: the array of pointers to be sorted
*     size: the number of pointers in the array
*
* Output:
*     return: none
*     reference parameters: array, now sorted
*     streams: none
*/
void bubbleSort(int *array, int size){
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - 1; j++)
      if (*(array + j) > *(array + j+1))
        swap(array[j], array[j+1]);
}

/*
* largestValue
*
* This function returns the largest value from an array of pointers.
*
* Parameters:
*     array: the array of pointers to be checked
*     size: the number of pointers in the array
*
* Output:
*     return: the largest value pointed to by the array
*     reference parameters: array
*     streams: none
*/
int largestValue(int *array, int size){
  int max = *array;

  for (int i = 1; i < size; i++){
    if (*(array + i) > max)
      max = *(array + i);
  }

  return max;
}

/*
* smallestValue
*
* This function returns the smallest value from an array of pointers.
*
* Parameters:
*     array: the array of pointers to be checked
*     size: the number of pointers in the array
*
* Output:
*     return: the smallest value pointed to by the array
*     reference parameters: array
*     streams: none
*/
int smallestValue(int *array, int size){
  int min = *array;

  for (int i = 1; i < size; i++){
    if (*(array + i) < min)
      min = *(array + i);
  }

  return min;
}

/*
* averageValue
*
* This function returns the average value of an array of pointers.
*
* Parameters:
*     array: the array of pointers to be checked
*     size: the number of pointers in the array
*
* Output:
*     return: the average of all values pointed to by the array
*     reference parameters: array
*     streams: none
*/
double averageValue(int *array, int size){
  int sum = 0;
  double avg = 0;

  for (int i = 0; i < size; i++){
    sum += *(array + i);
  }
  avg = static_cast<double>(sum) / static_cast<double>(size);

  return avg;
}

/*
* medianValue
*
* This function returns the median value of an array of pointers.
* The array is sorted to find this value.
*
* Parameters:
*     array: the array of pointers to be checked
*     size: the number of pointers in the array
*
* Output:
*     return: the median value pointed to by the array
*     reference parameters: array, now sorted
*     streams: none
*/
int medianValue(int *array, int size){
  bubbleSort(array, size);
  int med_index = (size - 1) / 2;
  int med_val = *(array + med_index);

  return med_val;
}
