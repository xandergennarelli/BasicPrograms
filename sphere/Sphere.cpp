/*
* Author: Xander Gennarelli
* Assignment Title: Sphere Class
* Assignment Description:
*           A Sphere class that holds information for a constructed sphere.
* Due Date: 11/9/2020
* Date Created: 11/2/2020
* Date Last Modified: 11/2/2020
*/

#include "Sphere.h"

Sphere::Sphere(){
   radius = 1;
   color = "green";
}
Sphere::Sphere(double r){
   radius = r;
   color = "green";
}
Sphere::Sphere(double r, string c){
  radius = r;
  color = c;
}

void Sphere::setRadius(double r){
  radius = r;
}
void Sphere::setColor(string c){
  color = c;
}

double Sphere::getRadius() const{
  return radius;
}
string Sphere::getColor() const{
  return color;
}

double Sphere::area() const{
  return 4.0 * PI * pow(radius, 2);
}
double Sphere::volume() const{
  return (4.0 / 3.0) * PI * pow(radius, 3);
}

bool Sphere::isEqual(const Sphere other) const{
  bool x = false;
  if (radius == other.getRadius() && color == other.getColor()) x = true;
  return x;
}
