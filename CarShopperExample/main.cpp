#include <iostream>
#include <string>
#include "carShopper.h"

using namespace std;

const int MAX = 25;

int main(){
  Car theCars[MAX];
  Car *refToCars[Max];
  ifstream infile;

  for (int i = 0; i < MAX; i++){
    refToCars[i] = theCars + i;
  }

  infile.open("theCars");

  if (!infile){
    cerr << "Bad file" << endl;
    return 1;
  }

  while (getACar(infile, refToCars[count])){
    count++;
  }

  return 0;
}
