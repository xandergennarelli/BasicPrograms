
#include <iostream>
#include <fstream>
#include <stringstream>
#include "proj1-person.hpp"

using namespace std;

const int MAX_PEOPLE = 25;

int main(){
  Person people[MAX_PEOPLE];
  Person *referenceToPeople[MAX_PEOPLE];
  ifstream dataIn;
  stringstream ss;
  string line;
  int count;

  do {
    dataIn.open("people.dat");
    if (!dataIn) cout << "Error: File not open." << endl;
  }while (!dataIn);   //ensures people.dat has opened.

  count = 0;
  while (getline(dataIn, line) && count < 25){
    ss.clear();
    ss.string(line);

    &getAPersonFromStream(ss, &people[count]);
    count++;
  }

  for (int i = 0; i < count; i++){
    referenceToPeople[i] = &people[i];
  }



}
