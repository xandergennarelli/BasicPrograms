#include <fstream>
#include <iostream>
using namespace std;

int main(){
  ifstream ifs;
  ofstream ofs;
  int x = 0;
  ifs.open("sortedInts");

  ifs >> x;
  cout << x << endl;
  x++;

  ifs.close();
  ofs.open("sortedInts");
  ofs << x;

  return 0;
}
