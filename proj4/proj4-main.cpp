/**
-  file: proj4-main.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 4
-  due date: 03/03/2021
-
-  Date Modified: 03/03/2021
-    - File Created
*/

#include "proj4-ItemInfo.hpp"
#include <fstream>

using namespace std;

void growArr(ItemInfo*&, int&, const int);
void bubbleSortProfit(ItemInfo*, const int);

int main(){
  ifstream csv;
  char buffer[500], c, *item;
  int arrSize = 0, arrCap = 2, i = 0, mode = 0, letters = 0;
  ItemInfo *arr;

  csv.open("proj4-productServices.csv");
  if (!csv){
    printCString(cout, "Error: file not opened.\n");
    exit(1);
  }

  arr = new ItemInfo[arrCap];
  while (csv.get(c)){         //fill array of ItemInfo
    buffer[i] = c;
    if (c == ','){
      item = new char[letters+1];
      for (int j = 0; j < letters; j++){
        *(item + j) = buffer[i - letters + j];
      }
      *(item + letters) = '\0';
      switch (mode) {
        case 1:
          (arr + arrSize - 1)->setItemId(item);
          break;
        case 2:
          (arr + arrSize - 1)->setDescription(item);
          break;
        case 3:
          (arr + arrSize - 1)->setManCost(item);
          break;
      }
      delete [] item;
      mode++;
      letters = 0;
    }
    else if (c == '\n'){
      item = new char[letters+1];
      for (int j = 0; j < letters; j++){
        *(item + j) = buffer[i - letters + j];
      }
      *(item + letters) = '\0';
      (arr + arrSize - 1)->setSellPrice(item);
      mode = 0;
      letters = 0;
      delete [] item;
    }
    else {
      letters++;
      if(mode == 0){
        mode++;
        if (arrSize+1 > arrCap) growArr(arr, arrCap, arrSize);
        *(arr + arrSize) = ItemInfo();
        arrSize++;
      }
    }
    i++;
  }
  csv.close();

  for (int i = 0; i < arrSize; i++){
    (arr + i)->displayItemInfo(cout);
  }
  //
  // bubbleSortProfit(arr, arrSize);

  delete [] arr;
  return 0;
}

void growArr(ItemInfo *&a, int &c, const int s){
  c += 2;
  ItemInfo *newArr = new ItemInfo[c];
  for (int i = 0; i < s; i++){
    newArr[i] = a[i];
  }
  delete [] a;
  a = newArr;
}

void bubbleSortProfit(ItemInfo *a, const int s){
  ItemInfo *tmp;
  for (int i = 0; i < s - 1; i++)
    for (int j = 0; j < s - 1; j++)
      if ((a + j)->calcProfit() > (a + j+1)->calcProfit()){
        *tmp = *(a + j);
        *(a + j) = *(a + j+1);
        *(a + j+1) = *tmp;
      }
}
