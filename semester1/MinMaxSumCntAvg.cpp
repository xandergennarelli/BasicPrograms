/*
* Author: Xander Gennarelli
* Assignment Title: Min Max Sum Count Average
* Assignment Description:
*           A program that reads an unknown number of integers from a file and
*                   calculates the min, max, sum, count, and average of those
*                   values.
* Due Date: 9/23/2020
* Date Created: 9/21/2020
* Date Last Modified: 9/23/2020
*/
/*
* Data Abstraction:
*           Creates the string fileName to hold the user input file name.
*           Creates the input filestream inData.
*           Creates variables sum, count, min, max, range to hold their given
*                 integer values.
*           Creates the values average and midrange to hold double values.
* Input:
*           The user enters a file name.
*           The file stream is opened.
*           An error is printed if the file stream fails to open.
*           The file is read one int at a time.
*           The file stream is closed.
* Process:
*           Count is increased each time input is read.
*           Each new data point is added to sum.
*           Min and max are found.
*           Average, range, and midrange is found.
* Output:
*           The user is asked for a file name.
*           The file name is echo printed.
*           Min, max, sum, count, and average are printed.
*           Start extra credit is printed.
*           Range and midrange are printed.
*           End extra credit is printed.
* Assumptions:
*           It is assumed that the user will enter the file name of a
*                 correctly formated data file.
*           It is assumed that the user only wants answers based on integer
*                 data.
*           It is assumed that no value will be outside of the range of
*                 possible int values.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
  //DATA ABSTRACTION
  string fileName;
  ifstream inData;
  int sum = 0, count = 0, n, min, max, range;
  double average, midrange;

  //INPUT
  do {
    cout << "Enter Data File Name: ";
    cin >> fileName;
    //Echo Print
    cout << fileName << endl;

    inData.open(fileName.c_str());
    if(!inData) {
      cout << "ERROR: File not open." << endl;
    }
  }while(!inData);

  //PROCESS
  while(inData >> n) { //input read each loop
    count++;
    sum += n;

    if(count == 1){
      min = max = n;
    }
    if(min > n){
      min = n;
    }
    if(max < n){
      max = n;
    }
  }
  inData.close(); //input file stream closed

  average = static_cast<double>(sum) / count;

  cout << "Min = " << min << endl;
  cout << "Max = " << max << endl;
  cout << "Sum = " << sum << endl;
  cout << "Count = " << count << endl;
  cout << "Average = " << fixed << setprecision(3) << average << endl;

  cout << "\n*** Start Extra Credit ***\n" << endl;

  range = max - min;
  midrange = static_cast<double>(min + max) / 2.0;

  cout << "Range = " << range << endl;
  cout << "Midrange = " << fixed << setprecision(3) << midrange << endl;

  cout << "\n*** End Extra Credit ***" << endl;
  return 0;
}
