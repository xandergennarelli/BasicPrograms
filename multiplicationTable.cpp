/*
* Author: Xander Gennarelli
* Assignment Title: Multiplication Table
* Assignment Description:
*
* Due Date: 10/7/2020
* Date Created: 10/6/2020
* Date Last Modified: 10/7/2020
*/
/*
* Data Abstraction:
*           Creates rBeg, rEnd, cBeg, and cEnd to hold values for the first and
*                 last values of the two list of integers to be multiplied.
*           Creates rDelta and cDelta, both set to equal 1, to hold the whether
*                 the list is going from lesser to greater or greater to
*                 lesser.
*           Creates rSize and cSize to hold the size of each list of numbers
*                 being multiplied.
*           Creates spacing to assist in formatting output with correct amount
*                 of whitespace.
*           Creates divider to hold the dividing lines for formatting output.
*           Creates tableOut to hold the formatted output.
*           Creates row, col, and table to hold the two lists of numbers to be
*                 multiplied and the products respectively.
* Input:
*           rBeg, rEnd, cBeg, and cEnd are input by the user.
* Process:
*           rSize and cSize are calculated.
*           rDelta and cDelta are calculated.
*           col is populated.
*           divider is generated.
*           The first line of formatted output is pushed to tableOut.
*           row is populated.
*           The products are calculated, formatted, and pushed to tableOut.
* Output:
*           tableOut is printed.
* Assumptions:
*           It is assumed that the user inputs correctly.
*           It is assumed that the user only wants a 2d table.
*           It is assumed that the user will only wants to find products of
*                 integers.
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
  //DATA ABSTRACTION
  int rBeg, rEnd, cBeg, cEnd, rDelta = 1, cDelta = 1, rSize, cSize, spacing;
  string divider;
  stringstream tableOut;

  //INPUT
  cout << "Please Enter Four Integers R1 R2 C1 C2: ";
  cin >> rBeg >> rEnd >> cBeg >> cEnd;
  cout << rBeg << " " << rEnd << " " << cBeg << " " << cEnd << endl;//echoPrint
  rSize = abs(rEnd - rBeg) + 1;
  cSize = abs(cEnd - cBeg) + 1;
  int row[rSize];
  int col[cSize];
  int table[rSize][cSize];

  //PROCESS
  if(rEnd - rBeg < 0) rDelta = -1;
  if(cEnd - cBeg < 0) cDelta = -1;

  for(int i = 0; i < cSize; i++){
    col[i] = cBeg + (i * cDelta);

    spacing = 6;
    if(i == 0){
      tableOut << "       ";
      divider = "-----|";
    }
    if(col[i] >= 0){
      tableOut << " ";
      spacing = 5;
    }
    tableOut << left << setfill(' ') << setw(spacing) << col[i];
    divider += "-----|";
  }
  for(int i = 0; i < rSize; i++){
    row[i] = rBeg + (i * rDelta);
  }

  tableOut << endl << divider << endl;
  for(int i = 0; i < rSize; i++){
    tableOut << left << setfill(' ') << setw(8) << row[i];
    for(int j = 0; j < cSize; j++){
      table[i][j] = col[j] * row[i];
      tableOut << left << setfill(' ') << setw(6) << table[i][j];
    }
    tableOut << endl << divider << endl;
  }

  //OUTPUT
  cout << tableOut.str();

  return 0;
}
