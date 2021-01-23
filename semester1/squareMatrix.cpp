/*
* Author: Xander Gennarelli
* Assignment Title: Square Matrix
* Assignment Description:
*         A program that creates square matrices with larger values at the
*               center and smaller values at the edges like a pyramid.
* Due Date: 10/21/2020
* Date Created: 10/19/2020
* Date Last Modified: 10/21/2020
*/
/*
* Data Abstraction:
*         Creates the constant MAX_N set to 100 to hold the max square size.
*         Creates size and min to hold the size of a given square and the next
*               calculated value in a square.
*         Creates mat to hold the generated squares.
* Input:
*         The size of each square is read in one at a time, ending on 0.
* Process:
*         Smallest out of each of the following value is found :
*               column + 1, row + 1, size - column, size - row.
*         That value is inserted at that row and column.
* Output:
*         The square of the given size is iterated through and printed.
* Assumptions:
*         It is assumed the user only inputs positive integers.
*         It is assumed the user inputs correctly.
*/

#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main(){
  //DATA ABSTRACTION
  const int MAX_N = 100;
  int size, min, mat[MAX_N][MAX_N];

  //INPUT
  while (cin >> size && size != 0){
    //PROCESS
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        min = j + 1;
        if (min > i + 1) min = i + 1;
        if (min > size - j) min = size - j;
        if (min > size - i) min = size - i;

        mat[i][j] = min;
      }
    }
    //OUTPUT
    for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++){
        if (j > 0) cout << " ";
        cout << setfill(' ') << setw(3) << mat[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
