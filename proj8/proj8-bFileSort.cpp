/**
-  file: proj8-bFileSort.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 8
-  due date: 04/05/2021
-
-  Date Modified: 04/01/2021
-    - File Created
-
-  xxx
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

  size = (int)fs.tellg(); // size of file in bytes
  fDat = new int[size / INT_SIZE];

  fs.seekg(0, ios::beg);
  fs.read((char*)fDat, size);
  for (int i = 0; i < size / INT_SIZE; i++){
    cout << fDat[i] << endl;
  }
  cout << endl;

  delete [] fDat;

  usrDat = new int;
  cout << "ENTER AN INTEGER :: ";
  cin >> *usrDat;
  cout << endl;

  if (size == 0){
    fs.write((char*)usrDat, INT_SIZE);
  }
  else{
    fDat = new int;
    fs.seekg(INT_SIZE * (-1), ios::end);
    readPos = (int)fs.tellg();
    fs.seekp(0, ios::end);
    writePos = (int)fs.tellp();

    while (!done){
      fs.seekg(readPos, ios::beg);
      fs.read((char*)fDat, INT_SIZE);
      fs.seekp(writePos, ios::beg);

      if (*fDat <= *usrDat){
        fs.write((char*)usrDat, INT_SIZE);
        done = true;
      }
      else if (readPos == 0 && *fDat > *usrDat){
        fs.write((char*)fDat, INT_SIZE);
        fs.seekp(0, ios::beg);
        fs.write((char*)usrDat, INT_SIZE);
        done = true;
      }
      else{
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
