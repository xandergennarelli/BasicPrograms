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
    //*************************************************************************
    Sphere(double);

    //*************************************************************************
    // description: constructor with specified radius and color
    // return: none
    // precondition: some double and string values exist
    // postcondition: a Sphere exists
    //*************************************************************************
    Sphere(double, string);

    //*************************************************************************
    // description:
    // return:
    // precondition:
    // postcondition:
    //*************************************************************************
    void setRadius(double);

    //*************************************************************************
    // description:
    // return:
    // precondition:
    // postcondition:
    //*************************************************************************
    void setColor(string);

    //*************************************************************************
    // description:
    // return:
    // precondition:
    // postcondition:
    //*************************************************************************
    double getRadius() const;

    //*************************************************************************
    // description:
    // return:
    // precondition:
    // postcondition:
    //*************************************************************************
    string getColor() const;

    //*************************************************************************
    // description:
    // return:
    // precondition:
    // postcondition:
    //*************************************************************************
    double area() const;

    //*************************************************************************
    // description:
    // return:
    // precondition:
    // postcondition:
    //*************************************************************************
    double volume() const;


    //*************************************************************************
    // description:
    // return:
    // precondition:
    // postcondition:
    //*************************************************************************
    bool isEqual(const Sphere) const;
};

#endif //SPHERE_H
