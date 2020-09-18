#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    string fileName;
    ifstream inData;
    int sum = 0, count = 0, n;
    double average;

    //cout << "Enter File Name: ";

    //cin >> fileName;

    //inData.open(fileName.c_str());
    inData.open("myData.txt");

    //This only works in C++ 11.
    //Older looks like:
    //inData.open(fileName.c_str())
    //Always test the connection of this file opening.

    //Files always hold true if open.
    if(!inData) {
        cout << "ERROR: File not open - " << fileName << endl;
        exit(1);
    }

    //Use this way of reading files.

    while(inData >> n) {
        count++;
        sum += n;
    }

    average = static_cast<double>(sum) / count;

    cout << "Count   = " << count << endl;
    cout << "Sum     = " << sum << endl;
    cout << "Average = " << average << endl;
    return 0;
}
