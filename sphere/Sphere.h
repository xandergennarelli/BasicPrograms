/*
* Author: Xander Gennarelli
* Assignment Title: Sphere Class
* Assignment Description:
*           A Sphere class that holds information for a constructed sphere.
* Due Date: 11/9/2020
* Date Created: 11/2/2020
* Date Last Modified: 11/2/2020
*/
#ifndef SPHERE_H
#define SPHERE_H

#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159;

class Sphere{
  private:
    double radius;
    string color;
  public:
    //*************************************************************************
    // description: default constructor
    // return: none
    // precondition: none
    // postcondition: a Sphere exists
    //*************************************************************************
    Sphere();

    //*************************************************************************
    // description: constructor with specified radius
    // return: none
    // precondition: some double value exists
    // postcondition: a Sphere exists
    //                double is unchanged
    //*************************************************************************
    Sphere(double);

    //*************************************************************************
    // description: constructor with specified radius and color
    // return: none
    // precondition: some double value and string exist
    // postcondition: a Sphere exists
    //                double and string are unchanged
    //*************************************************************************
    Sphere(double r, string c);

    //*************************************************************************
    // description: sets the radius of the sphere
    // return: void
    // precondition: some double value exists
    // postcondition: the radius of the sphere is the double value
    //                double is unchanged
    //*************************************************************************
    void setRadius(double);

    //*************************************************************************
    // description: sets the color of the sphere
    // return: void
    // precondition: some string exists
    // postcondition: the color of the sphere is the string
    //                string is unchanged
    //*************************************************************************
    void setColor(string c);

    //*************************************************************************
    // description: returns the radius of the sphere
    // return: double
    // precondition: none
    // postcondition: sphere is unchanged
    //*************************************************************************
    double getRadius() const;

    //*************************************************************************
    // description: returns the color of the sphere
    // return: string
    // precondition: none
    // postcondition: sphere is unchanged
    //*************************************************************************
    string getColor() const;

    //*************************************************************************
    // description: returns the area of the sphere
    // return: double
    // precondition: none
    // postcondition: sphere is unchanged
    //*************************************************************************
    double area() const;

    //*************************************************************************
    // description: returns the volume of the sphere
    // return: double
    // precondition: none
    // postcondition: sphere is unchanged
    //*************************************************************************
    double volume() const;


    //*************************************************************************
    // description: Returns true if two spheres radius and color are the same
    // return: bool
    // precondition: some sphere exists
    // postcondition: both spheres are unchanged
    //*************************************************************************
    bool isEqual(const Sphere other) const;
};

#endif //SPHERE_H
