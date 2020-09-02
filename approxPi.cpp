/*
* Author: Xander Gennarelli
* Assignment Title: Approximate
* Assignment Description: Use a formula to output approximations of pi to
*                         varying degrees of accuracy.
* Due Date: 9/4/2020
* Date Created: 9/1/2020
* Date Last Modified: 9/1/2020
*/

#include <iostream>
#include <iomanip>
using namespace std;

double approximate(int loopNum){
  double out = 0;
  int sign = 1;

  for(double i = 1.0; i < loopNum * 2; i += 2){
    out += (1/i) * sign;
    sign *= -1;
  }

  return out * 4;
}

int main(){
  cout << "PI = " << approximate(6) << endl;
  cout << "PI = " << approximate(7) << endl;

  cout << "\n*** Start Extra Credit ***\n" << endl;

  cout << "PI = " << round((approximate(152)) * 100) / 100 << endl;

  cout << "\n*** End Extra Credit ***" << endl;
  return 0;
}
