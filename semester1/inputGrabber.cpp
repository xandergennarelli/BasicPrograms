/*
* Author: Xander Gennarelli
* Assignment Title: Awesome Square
* Assignment Description:
*           A program that will calculate if a square is awesome and/or magic
*                 or neither.
* Due Date: 10/2/2020
* Date Created: 10/1/2020
* Date Last Modified: 10/2/2020
*/
/*
* Data Abstraction:
*         IM JUST TRYING TO FIGURE STUFF OUT MAN.
* Input:
*         IM JUST TRYING TO FIGURE STUFF OUT MAN.
* Process:
*         IM JUST TRYING TO FIGURE STUFF OUT MAN.
* Output:
*         IM JUST TRYING TO FIGURE STUFF OUT MAN.
* Assumptions:
*         IM JUST TRYING TO FIGURE STUFF OUT MAN.
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  // string out;
  string line, dataFileName;
  ofstream inFile;
  /*
  while(getline(cin, out)){
    cout << out << endl;
    out = "";
  }
  */
  do {
    cin >> dataFileName;
    cout << dataFileName << endl << endl; //echo print

    inFile.open(dataFileName.c_str());
    if (!inFile){
      cout << "Error: File Not Open." << endl;
    }
  }while (!inFile);

  while (getline(inFile, line)){
    cout << line << endl;
  }
  inFile.close();

  return 0;
}
