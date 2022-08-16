#include <iostream>
#include <fstream>
using namespace std;

int main(){
  fstream fs;
  int *fDat, size, readPos;
  bool done;

  fDat = new int[4];
  fDat[0] = 1;
  fDat[1] = 2;
  fDat[2] = 3;
  fDat[3] = 4;

  fs.open("t.dat", ios::in | ios::out | ios::binary);

  cout << fs.tellp() << endl;
  fs.write((char*)fDat, 16);

  cout << fs.tellp() << endl;
  cout << fs.tellg() << endl;

  fs.seekp(0, ios::beg);
  cout << fs.tellp() << endl;
  cout << fs.tellg() << endl;

  fs.seekg(-4, ios::end);
  cout << fs.tellp() << endl;
  cout << fs.tellg() << endl;

  return 0;
}
