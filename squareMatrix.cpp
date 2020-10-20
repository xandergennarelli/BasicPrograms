/*
* Author: Xander Gennarelli
* Assignment Title:
* Assignment Description:
*
* Due Date: 10/21/2020
* Date Created: 10/19/2020
* Date Last Modified: 20/19/2020
*/
/*
* Data Abstraction:
*
* Input:
*
* Process:
*
* Output:
*
* Assumptions:
*
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <array>
using namespace std;

int main(){
  //DATA ABSTRACTION
  const int MAX_N = 100;
  int size, maxVal, rowMax, lastRowMax, val, lastVal, colDelta, rowDelta;
  int mat[MAX_N][MAX_N];
  stringstream ss;

  //PROCESS / INPUT
  while (cin >> size && size != 0){
    maxVal = size / 2;
    if (size % 2 != 0){
      maxVal++;
    }

    rowDelta = 1;
    lastRowMax = 0;
    for (int i = 0; i < size; i++){
      colDelta = 1;
      lastVal = 0;
      rowMax = lastRowMax + rowDelta;
      lastRowMax = rowMax;
      for (int j = 0; j < size; j++){
        val = lastVal + colDelta;
        lastVal = val;

        if (val == maxVal){
          colDelta = -1;
          if(j % 2 != 0 || j == 0){
            colDelta = 0;
          }
        }
        if (val > rowMax){
          val = rowMax;
        }

        mat[i][j] = val;
        cout << mat[i][j] << " ";
      }
      if (rowMax == maxVal){
        rowDelta = -1;
        if(i % 2 != 0 || i == 0){
          rowDelta = 0;
        }
      }
      cout << endl;
    }
  }
  //OUTPUT


  return 0;
}
