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
*         Creates the constants V_FLAG and C_FLAG to hold the color and volume
*               values that are checked for in the report.
*         Creates constant MAX_SIZE that holds the maximum number of spheres.
*         Creates spheres to hold spheres with the user input values.
*         Creates fName, line, and color to hold user input file name, lines
*               from the file, and colors read from the file.
*         Creates fsIn, ssIn, and ssOut to interact with the data file and
*               store the input and output.
*         Creates count, C_FLAG_count, and V_FLAG_count to hold the number of
*               spheres and the numebers of spheres that match the color flag
*               and are greater than or equal to the volume flag.
*         Creates radius, area, and volume to hold each of those values for
*               each sphere.
*         Creates sumArea, percent_C_FLAG, and avgArea to hold the calculated
*               values for the total area sum, percent of spheres matching
*               color flag, and the average area.
* Input:
*         The user inputs a file name.
*         The input file stream is opened.
*         The file is read line by line.
*         The input file stream is closed.
* Process:
*         The array of spheres is filled with the values from the data file.
*         The report table is formatted and stored in a string stream.
*         The C_FLAG_count, V_FLAG_count, and area sum is calculated.
*         The percent_C_FLAG and average area is calculated.
*         The end of the report is created.
*         The spheres are sorted by volume.
*         The spheres are sorted by color.
*         The extra credit report is created.
* Output:
*         The user is asked to enter a file name.
*         The file name is echo printed.
*         If the file fails to open, an error is printed.
*         The first report is printed.
*         The extra credit report is printed.
* Assumptions:
*         It is assumed the user will input correctly.
*         It is assumed the data file is formatted correctly.
*         It is assumed the user will eventually input a correct file name.
*         It is assumed the data file will not exceed 100 spheres.
*/

#include "Sphere.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

const double V_FLAG = 215.0;
const string C_FLAG = "red";
const int MAX_SIZE = 100;

int main() {
  Sphere spheres[MAX_SIZE];
  string fName, line, color;
  ifstream fsIn;
  stringstream ssIn, ssOut;
  int count = 0, C_FLAG_count = 0, V_FLAG_count = 0;
  double radius, area, volume, sumArea, percent_C_FLAG, avgArea;

  do{
    cout << "Enter file name: ";
    cin >> fName;
    cout << fName << endl; //echo print

    fsIn.open(fName.c_str());
    if (!fsIn) cout << "Error: File Not Open.";

    cout << endl;
  }while (!fsIn);

  getline(fsIn, line); // skip first
  getline(fsIn, line); // two lines

  while (getline(fsIn, line)){ //populate the array
    ssIn.clear();
    ssIn.str(line);

    ssIn >> radius >> color;
    spheres[count].setRadius(radius);
    spheres[count].setColor(color);

    count++;
  }
  fsIn.close();

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

    ssOut << setw(10) << i;
    ssOut << setw(10) << fixed << setprecision(2) << radius;
    ssOut << setw(10) << color;
    ssOut << setw(10) << fixed << setprecision(2) << area;
    ssOut << setw(10) << fixed << setprecision(2) << volume;
    ssOut << endl;

    if (color == C_FLAG) C_FLAG_count++;
    if (volume >= V_FLAG) V_FLAG_count++;
    sumArea += area;
  }

  percent_C_FLAG = static_cast<double>(C_FLAG_count)
                    / static_cast<double>(count) * 100;
  avgArea = sumArea / static_cast<double>(count);

  ssOut << endl << "Total Number of Spheres = " << count << "." << endl;
  ssOut << fixed << setprecision(2) << percent_C_FLAG
        << "% of Spheres are " << C_FLAG << "." << endl;
  ssOut << V_FLAG_count << " Spheres have a volume over "
        << static_cast<int>(V_FLAG) << "." << endl;
  ssOut << fixed << setprecision(2) << "Average Area = " << avgArea << endl;

  cout << ssOut.str();

  //Extra Credit
  ssOut.clear();
  ssOut.str("");
  ssOut << "\n\n*** Start Extra Credit ***\n\n" << endl;

  for (int i = 0; i < count - 1; i++){ //sub sort by volume
    for (int j = 0; j < count - 1; j++){
      if (spheres[j].volume() > spheres[j+1].volume()){
        swap(spheres[j], spheres[j+1]);
      }
    }
  }
  for (int i = 0; i < count - 1; i++){ //sort by color
    for (int j = 0; j < count - 1; j++){
      if (spheres[j].getColor() > spheres[j+1].getColor()){
        swap(spheres[j], spheres[j+1]);
      }
    }
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

    ssOut << setw(10) << i;
    ssOut << setw(10) << fixed << setprecision(2) << radius;
    ssOut << setw(10) << color;
    ssOut << setw(10) << fixed << setprecision(2) << area;
    ssOut << setw(10) << fixed << setprecision(2) << volume;
    ssOut << endl;
  }

  ssOut << endl << "Total Number of Spheres = " << count << "." << endl;
  ssOut << fixed << setprecision(2) << percent_C_FLAG
        << "% of Spheres are " << C_FLAG << "." << endl;
  ssOut << V_FLAG_count << " Spheres have a volume over "
        << static_cast<int>(V_FLAG) << "." << endl;
  ssOut << fixed << setprecision(2) << "Average Area = " << avgArea << endl;

  ssOut << "\n*** End Extra Credit ***" << endl;

  cout << ssOut.str();

  return 0;
}
