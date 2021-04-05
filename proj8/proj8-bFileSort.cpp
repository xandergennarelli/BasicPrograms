/**
-  file: proj8-bFileSort.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 8
-  due date: 04/05/2021
-
-  Date Modified: 04/04/2021
-    - Documentation added
-
-  Date Modified: 04/01/2021
-    - File Created
-    - Solution implemented
-
-  Uses a binary file to store a sorted list of integers entered by the user
*/

#include <iostream>
#include <fstream>
using namespace std;

const int INT_SIZE = 4;

int main(){
  fstream fs;
  int *fDat, *usrDat, size, readPos, writePos;
  bool done = false;

  fs.open("sortedInts", ios::in | ios::out | ios::binary | ios::ate);
  if (!fs){
    cout << "Error: File Not Opened." << endl;
    exit(1);
  }

  size = (int)fs.tellg() - 1; // size of file in bytes (-1 for the end newline)
  fDat = new int[size / INT_SIZE];

  fs.seekg(0, ios::beg);
  fs.read((char*)fDat, size); // read all data into memory
  if (size > 0){ // avoids printing 0 when file is empty
    for (int i = 0; i <= size / INT_SIZE; i++){ // print all previous values
      cout << fDat[i] << endl;
    }
  }
  cout << endl;
  delete [] fDat;

  //get next value from user
  usrDat = new int;
  cout << "ENTER AN INTEGER :: ";
  cin >> *usrDat;
  cout << *usrDat << endl; // echo print user value

  if (size == 0){ // if there were no previously stored values
    fs.write((char*)usrDat, INT_SIZE);
  }
  else{
    fDat = new int;
    fs.seekg(INT_SIZE * (-1), ios::end);
    readPos = (int)fs.tellg(); // readPos is position of the final value
    fs.seekp(0, ios::end);
    writePos = (int)fs.tellp(); // writePos is position after the final value

    while (!done){ // loop finds where to place user value in file
      fs.seekg(readPos, ios::beg);
      fs.read((char*)fDat, INT_SIZE); // read next file value
      fs.seekp(writePos, ios::beg);

      if (*fDat <= *usrDat){ // file value is less than or equal to user value
        fs.write((char*)usrDat, INT_SIZE);
        done = true;
      }
      else if (readPos == 0 && *fDat > *usrDat){ // user value should be first
        fs.write((char*)fDat, INT_SIZE);         // value in the file
        fs.seekp(0, ios::beg);
        fs.write((char*)usrDat, INT_SIZE);
        done = true;
      }
      else{ // final position of user value is not yet found
        fs.write((char*)fDat, INT_SIZE);
        writePos -= INT_SIZE;
        readPos -= INT_SIZE;
      }
    }

    delete fDat;
  }
  delete usrDat;
  fs.close();

  return 0;
}
