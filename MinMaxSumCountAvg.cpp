/*
* Author: Xander Gennarelli
* Assignment Title:
* Assignment Description:
* Due Date:
* Date Created:
* Date Last Modified:
*/
/*
* Data Abstraction:
* Input:
* Process:
* Output:
* Assumptions:
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    string fileName;
    ifstream inData;
    int sum = 0, count = 0, n, min, max, range;
    double average, midrange;

    do {
      cout << "Enter File Name: ";
      cin >> fileName;

      inData.open(fileName.c_str());
      if(!inData) {
          cout << "ERROR: File not open - " << fileName << "\n" << endl;
      }
    }while(!inData);

    while(inData >> n) {
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
    inData.close();

    average = static_cast<double>(sum) / count;

    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    cout << "Sum = " << sum << endl;
    cout << "Count = " << count << endl;
    cout << "Average = " << average << endl;

    cout << "\n*** Start Extra Credit ***\n" << endl;

    range = max - min;
    midrange = static_cast<double>(min + max) / 2.0;

    cout << "Range = " << range << endl;
    cout << "Midrange = " << average << endl;

    cout << "\n*** End Extra Credit ***" << endl;
    return 0;
}
