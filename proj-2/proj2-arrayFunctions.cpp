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

void bubbleSort(int *array, int size){
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - 1; j++)
      if (*(array + j) > *(array + j+1))
        swap(array[j], array[j+1]);
}

int largestValue(int *array, int size){
  int max = *array;

  for (int i = 1; i < size; i++){
    if (*(array + i) > max)
      max = *(array + i);
  }

  return max;
}

int smallestValue(int *array, int size){
  int min = *array;

  for (int i = 1; i < size; i++){
    if (*(array + i) < min)
      min = *(array + i);
  }

  return min;
}

double averageValue(int *array, int size){
  int sum = 0;
  double avg = 0;

  for (int i = 0; i < size; i++){
    sum += *(array + i);
  }
  avg = static_cast<double>(sum) / static_cast<double>(size);

  return avg;
}

int medianValue(int *array, int size){
  bubbleSort(array, size);
  int med_index = size / 2;
  int med_val = *(array + med_index);

  return med_val;
}
