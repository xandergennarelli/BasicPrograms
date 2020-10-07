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

  for(int i = 0; i < rSize; i++){
    row[i] = rBeg + (i * rDelta);

    spacing = 6;
    if(i == 0){
      tableOut << "       ";
      divider = "-----|";
    }
    if(row[i] >= 0){
      tableOut << " ";
      spacing = 5;
    }
    tableOut << left << setfill(' ') << setw(spacing) << row[i];
    divider += "-----|";
  }
  for(int i = 0; i < cSize; i++){
    col[i] = cBeg + (i * cDelta);
  }

  tableOut << endl << divider << endl;
  for(int i = 0; i < rSize; i++){
    tableOut << left << setfill(' ') << setw(8) << col[i];
    for(int j = 0; j < cSize; j++){
      table[i][j] = row[i] * col[j];
      tableOut << left << setfill(' ') << setw(6) << table[i][j];
    }
    tableOut << endl << divider << endl;
  }

  //OUTPUT
  cout << tableOut.str();

  return 0;
}
