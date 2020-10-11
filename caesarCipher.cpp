/*
* Author: Xander Gennarelli
* Assignment Title: CaesarCipher
* Assignment Description:
*           A program that will encrypt or decrypt an input message using a
*                 caesar cipher with a shift value of three.
* Due Date: 10/12/2020
* Date Created: 10/11/2020
* Date Last Modified: 10/11/2020
*/
/*
* Data Abstraction:
*           Creates fName and command to hold the two user input values.
*           Creates line to hold lines from the input file.
*           Creates inFile and outFile to read and write to the input and
*                 output files.
*           Creates inS and outS to process lines of input data and hold the
*                 shifted output.
*           Creates c to hold a given character of input from the file.
*           Creates delta to hold the value that each character is shifted.
*           Creates a, e, i, o, u, and y, to hold the frequency that each
*                 letter has in the input message.
* Input:
*           User inputs the input file name.
*           User inputs the desired command.
*           An input file stream is opened.
*           Lines are read from the ifstream one at a time.
*           Once all lines have been read the stream is closed.
* Process:
*           If the command is decrypt then delta is set to -3 so that the
*                 message is shifted in backwards.
*           The input string stream is cleared and filled with a line read from
*                 the input file.
*           A character is read from the string stream.
*           If the character is a vowel it is recorded in that vowels count.
*           The character is shifted and pushed into an output string stream.
* Output:
*           The output file stream is opened.
*           The output string stream is printed to the output file.
*           The output file is closed.
*           The output string stream is printed to the screen.
*           Start extra credit is printed.
*           The frequency of each vowel is printed.
*           End extra credit is printed.
* Assumptions:
*           It is assumed the user will input correctly.
*           It is asssumed that the input file has content.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  //DATA ABSTRACTION
  string fName, command, line;
  ifstream inFile;
  ofstream outFile;
  stringstream inS, outS;
  char c;
  int delta = 3, a = 0, e = 0, i = 0, o = 0, u = 0, y = 0;

  //INPUT
  cout << "Enter File Name: ";
  cin >> fName;
  cout << fName << endl; //echo print
  cout << "Enter encrypt or decrypt: ";
  cin >> command;
  cout << command << endl; //echo print

  inFile.open(fName.c_str());
  if(!inFile){
    cout << "Error: File did NOT open." << endl;
    exit(1);
  }
  if(command != "encrypt" && command != "decrypt"){
    cout << "Error: Bad Command." << endl;
    exit(1);
  }
  if(command == "decrypt"){
    delta = -3;
  }

  //PROCESS
  while(getline(inFile, line)){
    inS.clear();
    inS.str(line);

    while(inS.get(c) && c != '\n'){
      switch(c){
        case 'a': case 'A': a++; break;
        case 'e': case 'E': e++; break;
        case 'i': case 'I': i++; break;
        case 'o': case 'O': o++; break;
        case 'u': case 'U': u++; break;
        case 'y': case 'Y': y++; break;
      }
      c += delta;
      outS << c;
    }
    outS << endl;
  }
  inFile.close();

  //OUTPUT
  outFile.open("message");
  outFile << outS.str();
  outFile.close();
  cout << outS.str();

  //EXTRA CREDIT
  cout << "\n*** Start Extra Credit ***\n" << endl;

  cout << "Letter Frequency" << endl;
  cout << "   A" << setw(7) << a << endl;
  cout << "   E" << setw(7) << e << endl;
  cout << "   I" << setw(7) << i << endl;
  cout << "   O" << setw(7) << o << endl;
  cout << "   U" << setw(7) << u << endl;
  cout << "   Y" << setw(7) << y << endl;

  cout << "\n*** End Extra Credit ***" << endl;

  return 0;
}
