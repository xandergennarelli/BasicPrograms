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
*           Creates root1 and root2 to hold the roots of the quadratic.
*           Creates vertX and vertY to hold the coordinates of the vertex of
*                 the equation.
* Input:
*           User inputs the values a, b, and c.
* Process:
*           The discriminant is calculated and used to find the number of
*                 roots.
*           The roots are calculated if they exist.
*           The roots are reordered, if necessary, to ensure root1 is less than
*                 root2.
*           The x and y coordinates of the vertex are calculated.
* Output:
*           Prints the roots if they exist or "NO REAL ROOTS" if they are not
*                 real. If the roots are identical, only one is printed.
*           Prints two lines of whitespace.
*           Prints start extra credit.
*           Prints the vertex of the function.
*           Prints the end extra credit.
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
  int a, b, c, d, numRoots;
  double root1, root2, vertX, vertY;
  //string userIn;

  //Input
  cin >> a >> b >> c;

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

  cout << "\n" << endl;

  //Extra Credit
  cout << "\n*** Start Extra Credit ***\n" << endl;

  vertX = static_cast<double>(-1 * b) / static_cast<double>(2 * a);
  vertY = a * pow(vertX, 2.0) + static_cast<double>(b) * vertX
          + static_cast<double>(c);

  cout << "Vertex = ("<< fixed << setprecision(2) << vertX << ", " << vertY
       << ")" << endl;

  cout << "\n*** End Extra Credit ***" << endl;

  return 0;
}
