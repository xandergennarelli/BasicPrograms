#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //for swap()
using namespace std;

int main() {
    string fileName;
    ifstream inData;
    int sum = 0, count = 0, n, min, max;
    double average;

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

    cout << "Count   = " << count << endl;
    cout << "Sum     = " << sum << endl;
    cout << "Min     = " << min << endl;
    cout << "Max     = " << max << endl;
    cout << "Average = " << average << endl;
    return 0;
}
