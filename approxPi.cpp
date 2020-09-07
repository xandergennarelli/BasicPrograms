/*
* Author: Xander Gennarelli
* Assignment Title: Approximate
* Assignment Description: Use a formula to output approximations of pi to
*                         varying degrees of accuracy.
* Due Date: 9/4/2020
* Date Created: 9/1/2020
* Date Last Modified: 9/4/2020
*/

#include <iostream>
#include <iomanip>
using namespace std;

double approximate(double loopNum){
  double out = 0.0;
  double sign = 1.0;

  for(double i = 1.0; i < loopNum * 2.0; i += 2.0){
    out += (1.0/i) * sign;
    sign *= -1.0;
  }

  return out * 4.0;
}

int main(){
  cout << "PI = " << approximate(6) << endl;
  cout << "PI = " << approximate(7) << endl;

  cout << "\n*** Start Extra Credit ***\n" << endl;

  cout << "PI = " << fixed << setprecision(2) << approximate(152) << endl;

  cout << "\n*** End Extra Credit ***" << endl;
  return 0;
}
