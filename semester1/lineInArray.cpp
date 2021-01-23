/*
* Author: Xander Gennarelli
* Assignment Title: Line In Array
* Assignment Description:
*           A program that will create a matrix and return either the sum or
*                 average of a row of that matrix.
* Due Date: 10/24/2020
* Date Created: 10/25/2020
* Date Last Modified: 10/24/2020
*/
/*
* Data Abstraction:
*           Creates row and op to hold the user input row and operation.
*           Creates sum and avg to hold the calculated values of sum and mean.
*           Creates matrix to hold the matrix of user input values.
* Input:
*           The user inputs a row and an operation.
*           The user inputs 144 double values that are placed in a 2d array.
* Process:
*           The selected row is summed and then the mean is found.
* Output:
*           If the user requested the sum, it is printed.
*           If the user requested the mean, it is printed.
* Assumptions:
*           The user will input correctly.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  //DATA ABSTRACTION
  int row;
  char op;
  double sum = 0, avg, matrix[12][12];

  //INPUT
  cin >> row >> op;
  for (auto & r:matrix){
    for (auto & c:r){
      cin >> c;
    }
  }

  //PROCESS
  for (auto c:matrix[row]){
    sum += c;
  }
  avg = sum / 12.0;

  //OUTPUT
  if (op == 'S') cout << fixed << setprecision(1) << sum << endl;
  if (op == 'M') cout << fixed << setprecision(1) << avg << endl;

  return 0;
}
