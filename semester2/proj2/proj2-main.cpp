/**
-  file: proj2-main.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Lab 2
-  due date: 02/01/2021
-
-  Date Modified: 01/30/2021
-    - File Created
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "proj2-arrayFunctions.h"

using namespace std;

int main(){
  ifstream dataIn;
  stringstream ss;
  string line;
  int size, min, max, avg, med, min_all, max_all, count = 0;
  int *p_arr;

  dataIn.open("arrays.txt");
  if (!dataIn){
    cout << "Error: File not open." << endl;
    exit(1);
  }

  while(getline(dataIn, line)){
    ss.clear();
    ss.str(line);

    ss >> size;
    getline(dataIn, line);
    ss.clear();
    ss.str(line);

    p_arr = new int[size];

    for (int i = 0; i < size; i++){
      ss >> *(p_arr + i);
    }

    min = smallestValue(p_arr, size);
    max = largestValue(p_arr, size);
    avg = averageValue(p_arr, size);
    med = medianValue(p_arr, size);

    if (count == 0){
      min_all = min;
      max_all = max;
    }
    else {
      if (min < min_all) min_all = min;
      if (max > max_all) max_all = max;
    }
    cout << "Array #" << count + 1 << ":" << endl;
    cout << "minimum = " << min << endl;
    cout << "maximum = " << max << endl;
    cout << "average = " << avg << endl;
    cout << "median  = " << med << endl;
    cout << endl;

    delete p_arr;
    count++;
  }

  cout << "Overall min = " << min_all << endl;
  cout << "Overall max = " << max_all << endl;

  return 0;
}
