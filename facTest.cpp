#include <ctime>
#include <iostream>
using namespace std;

__int128 factorialR(__int128 x);
__int128 factorialL(__int128 x);

int main(){
  __int128 fr, fl;
  time_t frS, frE, flS, flE;
  double frSum = 0, flSum = 0, iter = 10000000;

  for (int i = 0; i < iter; i++){
    frS = clock();
    factorialR(9999);
    frE = clock();
    flS = clock();
    factorialL(9999);
    flE = clock();

    frSum += (double)(frE - frS);
    flSum += (double)(flE - flS);
  }

  cout << "fr :: " << frSum/iter << endl;
  cout << "fl :: " << flSum/iter << endl;

  return 0;
}

__int128 factorialR(__int128 x){
  if (x == 1) return 1;
  return x * factorialR(x-1);
}
__int128 factorialL(__int128 x){
  for (__int128 i = x - 1; i > 0; i--){
    x *= i;
  }
  return x;
}
