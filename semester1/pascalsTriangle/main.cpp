/*
* Author: Xander Gennarelli
* Assignment Title: Pascal's Triangle
* Assignment Description:
*           A program that will print a pascal's triangle of a given size.
* Due Date: 11/4/2020
* Date Created: 11/2/2020
* Date Last Modified: 11/2/2020
*/
/*
* Data Abstraction:
*           Creates n and spacing to hold values for the size of the triangle
*                 and the amount of spacing before each printed line.
*           Creates ssOut to hold all formatted output.
* Input:
*           The user enters the desired size of the triangle.
* Process:
*           The amount of pre-line spacing is calculated based on what line of
*                 the triangle is being calculated.
*           That spacing is stored in a string stream.
*           The next value of the triangle is calculated based on the line and
*                 the number of previous values calculated on that line.
*           The value is stored in a string stream left justified with spacing.
* Output:
*           The string stream is printed.
* Assumptions:
*           It is assumed the user only inputs positive integers that comply
*                 the factorial and combination functions.
*           It is assumed the user will input correctly.
*/

#include "myFunctions.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
  //DATA ABSTRACTION
  int n, spacing;
  stringstream ssOut;

  //INPUT
  cout << "Please Enter The Number of Rows: ";
  cin >> n;
  cout << n << "\n" << endl; //Echo Print

  //PROCESS
  for (int i = 0; i < n; i++){
    spacing = 4 * (n - i);
    ssOut << setfill(' ') << setw(spacing) << ' ';
    for (int j = 0; j <= i; j++){
      ssOut << setfill(' ') << setw(8) << left << combination(i, j);
    }
    ssOut << endl;
  }

  //OUTPUT
  cout << ssOut.str();

  //EXTRA CREDIT
  cout << "\n\n*** Start Extra Credit ***\n" << endl;

  ssOut.clear();
  ssOut.str("");
  for (int i = n - 1; i >= 0; i--){
    spacing = 4 * (n - i);
    ssOut << setfill(' ') << setw(spacing) << ' ';
    for (int j = 0; j <= i; j++){
      ssOut << setfill(' ') << setw(8) << left << combination(i, j);
    }
    ssOut << endl;
  }

  cout << ssOut.str();

  cout << "\n*** End Extra Credit ***" << endl;

  return 0;
}
