/*
* Author: Xander Gennarelli
* Assignment Title: Line Class
* Assignment Description:
*           A class that represents a line and can compare against other lines.
* Due Date: 11/13/2020
* Date Created: 11/9/2020
* Date Last Modified: 11/9/2020
*/

#include "Line.h"

Line::Line(){
  Point a, b(1, 1);
  p1 = a;
  p2 = b;
}
Line::Line(Point a, Point b){
  p1 = a;
  p2 = b;
}

void Line::setFirstPoint(Point a){
  p1 = a;
}
void Line::setSecondPoint(Point a){
  p2 = a;
}

Point Line::getFirstPoint() const{
  return p1;
}
Point Line::getSecondPoint() const{
  return p2;
}

bool Line::slope(double& m) const{
  bool hasSlope = false;
  if (p1.x != p2.x){
    hasSlope = true;
    m = (p2.y - p1.y) / (p2.x - p1.x);
  }
  return hasSlope;
}
bool Line::yIntercept(double& b) const{
  double m;
  bool hasYIntercept = false;
  if (slope(m)){
    hasYIntercept = true;
    b = p1.y - (m * p1.x);
  }
  return hasYIntercept;
}

bool Line::isParallel(Line a) const{
  double m, mA;
  bool isP = false;
  if (slope(m) && a.slope(mA)){
    if (m == mA) isP = true;
  }
  if (!slope(m) && !a.slope(mA)) isP = true;
  return isP;
}
bool Line::isCollinear(Line a) const{
  double b, bA, m;
  bool isC = false;
  if (isParallel(a)){
    yIntercept(b);
    a.yIntercept(bA);
    if (!slope(m) && p1.x == a.getFirstPoint().x) isC = true;
    else if (b == bA) isC = true;
  }
  return isC;
}
bool Line::isPerpendicular(Line a) const{
  double m, mA;
  bool isP = false, hasSlope = slope(m), hasSlopeA = a.slope(mA);
  if ((!hasSlope && mA == 0) || (m == 0 && !hasSlopeA)) isP = true;
  else if (hasSlope && hasSlopeA){
    if (m * mA == -1) isP = true;
  }
  return isP;
}

Point Line::intersect(Line a) const{
  Point i;
  double x, y, b, bA, m, mA;
  if (!slope(m)) x = getFirstPoint().x;
  else if (!a.slope(mA)) x = a.getFirstPoint().x;
  else {
    yIntercept(b);
    a.yIntercept(bA);
    x = (b - bA) / (m - mA);
  }
  y = m * x - b;
  i.x = x;
  i.y = y;

  return i;
}

void Line::display(ostream& os) const{
  double m, b;
  if (!slope(m)) os << "x = " << getFirstPoint().x;
  else {
    yIntercept(b);
    os << "y = ";
    if (m == 0) os << getFirstPoint().y;
    else {
      if (m == -1) os << "-";
      else if (m != 1) os << m;
      os << "x";
      if (b > 0) os << " + " << b;
      if (b < 0) os << " " << b;
    }
  }
}
