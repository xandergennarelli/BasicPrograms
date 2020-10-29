/*
* Author: Xander Gennarelli
* Assignment Title: My Functions
* Assignment Description:
*           A program that implements some 'useful' math functions using
*                 separate driver, implementation, and header files.
* Due Date: 10/30/2020
* Date Created: 10/28/2020
* Date Last Modified: 10/28/2020
*/
/*
* Data Abstraction:
*           Yeah Yeah Yeah Lemme Test My Code!!
* Input:
*           Yeah Yeah Yeah Lemme Test My Code!!
* Process:
*           Yeah Yeah Yeah Lemme Test My Code!!
* Output:
*           Yeah Yeah Yeah Lemme Test My Code!!
* Assumptions:
*           Yeah Yeah Yeah Lemme Test My Code!!
*/
#include "myFunctions.h"
#include <array>

int main() {
  int n[8];
  double d[20];

  assert((max(5, 10) == 10));
  assert((max(-3, -6) == -3));
  assert((max(0, 0) == 0));
  assert((max(0, 1) == 1));
  assert((max(-1, -0) == 0));
  cout << "max(int, int) passed!" << endl;

  assert((max(5.5, 1.7) == 5.5));
  assert((max(-8.3, -3.6) == -3.6));
  assert((max(0.0, 0.0) == 0.0));
  assert((max(0.0, 1.1) == 1.1));
  assert((max(-1.5, -0.0) == 0.0));
  cout << "max(double, double) passed!" << endl;

  n& = {5,3,-2,4,0,0,0,0};
  assert((max(n, 5) == 5));
  n = {5,3,-2,4,0,12,2,5};
  assert((max(n, 8) == 12));
  n = {0,0,0,1,0,0,0,0,12};
  assert((max(n, 8) == 1));
  n = {-8,-222222,-20,-10,-10,-10,-10,-10};
  assert((max(n, 3) == -8));
  n = {0,0,0,0,0,0,0,0};
  assert((max(n, 1) == 0));
  cout << "max(int m{}, int n) passed!"

  assert((max({5.0,3.2,-2.7,4.2,0.0}, 5) == 5.0));
  assert((max({5.0,3.2,-2.7,4.2,00.0, 12.7,2.2,5.1}, 8) == 12.7));
  assert((max({0.0,0.0,1.6,0.0,12.2}, 4) == 1.6));
  assert((max({-8.8,-222222.9,-20.09}, 3) == -8.8));
  assert((max({-0.0}, 1) == 0.0));
  cout << "max(double m{}, int n) passed!"

  assert((min(5, 10) == 5));
  assert((min(-3, -6) == -6));
  assert((min(0, 0) == 0));
  assert((min(1, 0) == 0));
  assert((min(-1, -0) == -1));
  cout << "min(int, int) passed!" << endl;

  assert((min(5.5, 1.7) == 1.7));
  assert((min(-8.3, -3.6) == -8.3));
  assert((min(0.0, 0.0) == 0.0));
  assert((min(0.0, -1.1) == -1.1));
  assert((min(1.5, -0.0) == 0.0));
  cout << "min(double, double) passed!" << endl;

  n = {5,3,-2,4,0};
  assert((min(n, 5) == 0));
  n = {5,3,-2,4,0,12,-2,5};
  assert((min(n, 8) == -2));
  assert((min({0,0,0,1,0,0,-200,200,12}, 8) == -200));
  assert((min({-8,-222222,-20}, 3) == -222222));
  assert((min({0}, 1) == 0));
  cout << "min(int m{}, int n) passed!"

  assert((min({5.0,3.2,-2.7,4.2,0.0}, 5) == -2.7));
  assert((min({5.0,3.2,-2.7,4.2,00.0, 12.7,2.2,-5.1}, 8) == -5.1));
  assert((min({0.0,0.0,-1.6,0.0,-12.2}, 4) == -1.6));
  assert((min({-8.8,-222222.9,-20.09}, 3) == -222222.9));
  assert((min({-0.0}, 1) == 0.0));
  cout << "min(double m{}, int n) passed!"

  cout << "All good!" << endl;

  return 0; //assert(( == ));
}
