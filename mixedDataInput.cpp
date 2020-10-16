/*
* Author: Xander Gennarelli
* Assignment Title: Mixed Data Input
* Assignment Description:
*           A program to separate the transaction data from several companies
*                 from one file into a file for each company.
* Due Date: 10/16/2020
* Date Created: 10/15/2020
* Date Last Modified: 10/16/2020
*/
/*
* Data Abstraction:
*         Creates inFile to read the input file.
*         Creates a, b, and c to write to the output files.
*         Creates ssIn, ssOut, ssA, ssB, and ssC to read lines of data, format
*               output, and store output for each of three output files.
*         Creates line and dataFileName to hold a given line of input data and
*               the input file name.
*         Creates count to help save the first two lines of the file.
*         Creates code, actNum, amount, and wd to hold the values in each line
*               of data.
* Input:
*         The user enters an input file name.
*         The input file stream is opened.
*         The file is read line by line.
*         The input file stream is closed.
* Process:
*         The first two input file lines are added to all three output streams.
*         The values are extracted from each line.
*         The values are pushed to the correct output stream, separated by
*               spaces as determined by the actNum of the line.
* Output:
*         The user is asked to enter a file name.
*         The file name is echo printed.
*         If the file does not open an error is printed.
*         The output file streams are opened and filled with the output string
*               streams.
*         The output file streams are closed.
* Assumptions:
*         It is assumed that the user inputs correctly.
*         It is assumed that the input file is formatted correctly.
*         It is assumed that the input file is not empty.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  //DATA ABSTRACTION
  ifstream inFile;
  ofstream a, b, c;
  stringstream ssIn, ssOut, ssA, ssB, ssC;
  string line, code, dataFileName;
  int actNum, count = 0;
  double amount;
  char wd;

  //INPUT / PROCESS
  do {
    cout << "Enter Name of Data File: ";
    cin >> dataFileName;
    cout << dataFileName << endl; //echo print

    inFile.open(dataFileName.c_str());
    if (!inFile){
      cout << "Error: File Not Open." << endl;
    }
  }while (!inFile);

  while (getline(inFile, line)){
    ssIn.clear();
    ssIn.str(line);
    ssOut.clear();
    ssOut.str("");
    actNum = -1;

    if (count < 2){
      ssA << ssIn.str() << endl;
      ssB << ssIn.str() << endl;
      ssC << ssIn.str() << endl;
      count++;
    }
    else{
      ssIn >> actNum >> amount >> wd >> code;
      ssOut << actNum << " " << amount << " " << wd << " " << code;
    }

    if (actNum >= 0 && actNum < 100){
      ssA << ssOut.str() << endl;
    }
    if (actNum >= 300 && actNum < 400){
      ssB << ssOut.str() << endl;
    }
    if (actNum >= 200 && actNum < 300){
      ssC << ssOut.str() << endl;
    }
  }
  inFile.close();

  //OUTPUT
  a.open("Company_A.txt");
  a << ssA.str();
  a.close();

  b.open("Company_B.txt");
  b << ssB.str();
  b.close();

  c.open("Company_C.txt");
  c << ssC.str();
  c.close();

  return 0;
}
