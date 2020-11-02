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
*           Yeah Yeah Yeah Lemme Test My Code!!
* Input:
*           Yeah Yeah Yeah Lemme Test My Code!!
* Process:
*           Yeah Yeah Yeah Lemme Test My Code!!
* Output:
*           Yeah Yeah Yeah Lemme Test My Code!!
* Assumptions:
*           Yeah Yeah Yeah Lemme Test My Code!!
*/

#include "myFunctions.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
  //DATA ABSTRACTION
  int n;
  stringstream ssOut;

  //INPUT
  cout << "Please Enter The Number of Rows: ";
  cin >> n;
  cout << n << endl; //Echo Print

  for (int i = 0; i < n; i++){
    ssOut << setfill(' ') << setw();
    for (int j = 0; j <= i; j++){
      ssOut << setfill(' ') << setw(8) << combination(i, j);
    }
    ssOut << endl;
  }


  cout << "\n*** Start Extra Credit ***\n" << endl;



  cout << "\n*** End Extra Credit ***" << endl;

  return 0;
}
