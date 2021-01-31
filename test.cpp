#include <iostream>

using namespace std;

int main(){
  float f = 3.14159, *fptr = &f;
  float *fptr2 = fptr + 3;

  cout << (long) fptr2 - (long) fptr << endl;
  cout << fptr2 - fptr << endl;


  return 0;
}
