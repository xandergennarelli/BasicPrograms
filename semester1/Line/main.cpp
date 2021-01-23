/*
* Author: Xander Gennarelli
* Assignment Title: System of Linear Equations
* Assignment Description:
*           A program that reads two linear equations and calculates the
*                 intersection if it exists.
* Due Date: 11/30/2020
* Date Created: 11/30/2020
* Date Last Modified: 11/30/2020
*/
/*
* Data Abstraction:
*           Creates lineIn1 and lineIn2 to hold user input lines.
*           Creates a1, b1, c1, a2, b2, and c2 to holf the coefficients.
*           Creates lineA and lineB to hold the calculated lines.
*           Creates intersectPoint to hold the point that the lines intersect.
* Input:
*           User inputs two lines containing linear equations.
* Process:
*           The three coefficients are found for each line.
*           The two lines are created.
*           If the intersection exists it is calculated.
* Output:
*           If the intersection exists it is reported.
*           If not, NO SOLUTION is printed.
* Assumptions:
*           it is assumed the user will input correctly.
*/

#include "Line.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

//*****************************************************************************
// description: Returns the coefficient of the x term.
// return: double
// precondition: Some string exists.
// postcondition: string is unchanged.
//*****************************************************************************
double getCoef_A(string);

//*****************************************************************************
// description: Returns the coefficient of the y term.
// return: double
// precondition: Some string exists.
// postcondition: string is unchanged.
//*****************************************************************************
double getCoef_B(string);

//*****************************************************************************
// description: Returns the coefficient of the third term.
// return: double
// precondition: Some string exists.
// postcondition: string is unchanged.
//*****************************************************************************
double getCoef_C(string);

//*****************************************************************************
// description: Returns line formed from three coefficients.
// return: Line
// precondition: Three double values exist.
// postcondition: double values are unchanged.
//*****************************************************************************
Line generateLine(double, double, double);

int main() {
  string lineIn1, lineIn2;
  double a1, b1, c1, a2, b2, c2;
  Line lineA, lineB;
  Point intersectPoint;

  getline(cin, lineIn1);
  getline(cin, lineIn2);

  a1 = getCoef_A(lineIn1);
  a2 = getCoef_A(lineIn2);
  b1 = getCoef_B(lineIn1);
  b2 = getCoef_B(lineIn2);
  c1 = getCoef_C(lineIn1);
  c2 = getCoef_C(lineIn2);

  lineA = generateLine(a1, b1, c1);
  lineB = generateLine(a2, b2, c2);

  if (lineA.isParallel(lineB) || lineA.isCollinear(lineB)){
    cout << "NO SOLUTION" << endl;
  }
  else{
    intersectPoint = lineA.intersect(lineB);

    cout << "SOLUTION: " << fixed << setprecision(3) << "(" << intersectPoint.x
         << "," << intersectPoint.y << ")" << endl;
  }

  return 0;
}

double getCoef_A(string line){
  stringstream ss(line);
  string token;
  double coef = 0;
  int side = 1, sign = 1;
  bool done = false;

  while (!done && ss >> token){
    if (token.find('x') != string::npos){
      done = true;
      if (token.size() == 1) coef = 1;
      else if (token == "-x") coef = -1;
      else {
        ss.clear();
        ss.str(token.substr(0, token.size() - 1));
        ss >> coef;
      }
    }
    else if (token == "="){
      side = -1;
    }
    else if (token == "-"){
      sign = -1;
    }
    else{
      sign = 1;
    }
  }

  return coef * side * sign;
}

double getCoef_B(string line){
  stringstream ss(line);
  string token;
  double coef = 0;
  int side = 1, sign = 1;
  bool done = false;

  while (!done && ss >> token){
    if (token.find('y') != string::npos){
      done = true;
      if (token.size() == 1) coef = 1;
      else if (token == "-y") coef = -1;
      else {
        ss.clear();
        ss.str(token.substr(0, token.size() - 1));
        ss >> coef;
      }
    }
    else if (token == "="){
      side = -1;
    }
    else if (token == "-"){
      sign = -1;
    }
    else{
      sign = 1;
    }
  }

  return coef * side * sign;
}

double getCoef_C(string line){
  stringstream ss(line);
  string token;
  double coef = 0;
  int side = 1, sign = -1;
  bool done = false;

  while (!done && ss >> token){
    if (token == "="){
      side = -1;
    }
    else if (token == "-"){
      sign = 1;
    }
    else if (token.find('y') == string::npos && token.find('x') == string::npos
        && token != "+"){
      done = true;
      ss.clear();
      ss.str(token);
      ss >> coef;
    }
    else{
      sign = -1;
    }
  }

  return coef * side * sign;
}

Line generateLine(double a, double b, double c){
  Point p1(c / a, 0.0), p2(0.0, c / b);
  Line line(p1, p2);
  return line;
}
