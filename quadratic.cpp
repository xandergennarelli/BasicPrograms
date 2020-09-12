/*
* Author: Xander Gennarelli
* Assignment Title: Quadratic Formula
* Assignment Description: A program that, given inputs of a, b, and c, will
*                         print both roots of the quadratic.
* Due Date: 9/14/2020
* Date Created: 9/12/2020
* Date Last Modified: 9/12/2020
*/
/*
* Data Abstraction:
* Input:
* Process:
* Output:
* Assumptions:
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

  //Data Abstraction
  int a, b, c, d, numRoots, index;
  double root1, root2;
  string userIn;

  //Input
  cout << "Please input a, b, and c :: ";
  getline(cin, userIn);
  cout << userIn << endl;

  index = userIn.find(',');

  a = stoi(userIn.substr(0, index));
  userIn = userIn.substr(index + 2);
  index = userIn.find(',');

  b = stoi(userIn.substr(0, index));
  userIn = userIn.substr(index + 2);

  c = stoi(userIn);

  //Process
  d = pow(b, 2) - (4 * a * c);
  if(d > 0){
    numRoots = 2;
  }
  else if(d == 0){
    numRoots = 1;
  }
  else{
    numRoots = 0;
  }


  if(numRoots > 0){
    root1 = static_cast<double>((b * -1) + sqrt(d))
            / (static_cast<double>(a) * 2.0);
    root2 = static_cast<double>((b * -1) - sqrt(d))
            / (static_cast<double>(a) * 2.0);
  }
  if(root1 > root2){
    double tmp = root1;
    root1 = root2;
    root2 = tmp;
  }

  //Output
  if(numRoots == 0){
    cout << "NO REAL ROOTS";
  }
  else{
    cout << fixed << setprecision(2) << root1;
  }
  if(numRoots > 1){
    cout << " " << fixed << setprecision(2) << root2;
  }

  cout << endl;

  return 0;
}
