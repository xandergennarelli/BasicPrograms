/*
* Author: Xander Gennarelli
* Assignment Title: Array of Spheres
* Assignment Description:
*           A program that fills an array of spheres and displays some
*                 information about that array.
* Due Date: 11/18/2020
* Date Created: 11/2/2020
* Date Last Modified: 11/18/2020
*/
/*
* Data Abstraction:
*           YEAH YEAH LEMME TEST MY CODE.
* Input:
*           YEAH YEAH LEMME TEST MY CODE.
* Process:
*           YEAH YEAH LEMME TEST MY CODE.
* Output:
*           YEAH YEAH LEMME TEST MY CODE.
* Assumptions:
*           YEAH YEAH LEMME TEST MY CODE.
*/
#include "Sphere.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  Sphere spheres[100];
  string fName, line, color;
  stringstream ssIn, ssOut;
  ifstream fsIn;
  int count = 0, count_red = 0, count_215 = 0;
  double radius, area, volume, sumArea = 0.0;

  do{
    cout << "Enter file name: ";
    cin >> fName;
    cout << fName << endl; //echo print

    fsIn.open(fName.c_str());
    if (!fsIn) cout << "Error: File Not Open." << endl;

    cout << endl;
  }while (!fsIn);

  getline(fsIn, line); // skip first
  getline(fsIn, line); // two lines
  while (getline(fsIn, line)){
    ssIn.clear();
    ssIn.str(line);

    ssIn >> radius >> color;
    spheres[count].setRadius(radius);
    spheres[count].setColor(color);

    count++;
  }

  ssOut << setw(10) << "Number";
  ssOut << setw(10) << "Radius";
  ssOut << setw(10) << "Color";
  ssOut << setw(10) << "Area";
  ssOut << setw(10) << "Volume";
  ssOut << endl;
  for (int i = 0; i < count; i++){
    radius = spheres[i].getRadius();
    color = spheres[i].getColor();
    area = spheres[i].area();
    volume = spheres[i].volume();

    ssOut << setw(10) << i + 1;
    ssOut << setw(10) << fixed << setprecision(2) << radius;
    ssOut << setw(10) << color;
    ssOut << setw(10) << fixed << setprecision(2) << area;
    ssOut << setw(10) << fixed << setprecision(2) << volume;
    ssOut << endl;

    if (color == "red") count_red++;
    if (volume >= 215.0) count_215++;
    sumArea += area;
  }

  ssOut << endl << "Total Number of Spheres = " << count << endl;
  ssOut << static_cast<double>(count_red) / static_cast<double>(count) * 100
        << fixed << setprecision(2) << "% of Spheres are red" << endl;
  ssOut << count_215 << " Spheres have a volume over 215." << endl;
  ssOut << fixed << setprecision(2) << "Average Area = "
        << sumArea / static_cast<double>(count) << endl;

  cout << ssOut.str();

  //Extra Credit


  return 0;
}
