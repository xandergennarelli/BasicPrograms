#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
  ifstream in;
  stringstream ss;
  string line, word, old;

  in.open("list.txt");

  while (getline(in, line)){
    ss.clear();
    ss.str(line);

    ss >> word;
    if (word != old){
      cout << word << endl;
    }

    old = word;
  }
  in.close();
  return 0;
}
