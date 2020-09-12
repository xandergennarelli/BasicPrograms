/*
* Author: Xander Gennarelli
* Assignment Title: Quadratic Formula
* Assignment Description: A program that, given inputs of a, b, and c, will
*                         print the roots of the quadratic or "NO REAL ROOTS".
* Due Date: 9/14/2020
* Date Created: 9/12/2020
* Date Last Modified: 9/12/2020
*/
/*
* Data Abstraction:
*           Creates a, b, and c to hold their counter-parts in the equation.
*           Creates d  and numRoots to hold the dicriminant and the
*                 number of roots.
*           Creates userIn to hold the users exact input.
*           Creates index as a placeholder for extracting values from userIn.
*           Creates root1 and root2 to hold the roots of the quadratic.
* Input:
*           User inputs the values a, b, and c delimited by a comma and a space.
*           The values of a, b, and c are extracted from the string and placed
*                 in their respective variables.
* Process:
*           The discriminant is calculated and used to find the number of roots.
*           The roots are calculated if they exist.
*           The roots are reordered, if necessary, to ensure root1 is less than
*                 root2.
* Output:
*           Asks the user to input a, b, and c.
*           Prints the roots if they exist or "NO REAL ROOTS" if they are not
*                 real. If the roots are identical, only one is printed.
* Assumptions:
*           It is assummed that the user will correctly input data.
*           It is assummed that the user only wants to solve one equation at a
*                 time.
*           It is assummed that the user only wants real solutions.
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
