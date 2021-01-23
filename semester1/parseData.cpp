#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

int main(){
  ifstream inputFile;
  string fileName;
  string line;
  stringstream ss;
  int id, min, max, sum, count;
  double avg;

  do{
    cout << "Enter file name: ";
    cin >> fileName;
    inputFile.open(fileName.c_str());
    if(!inputFile){
      cout << "Error: file not open." << endl;
    }
  }while(!inputFile);

  while(getline(inputFile, line)){
    cout << line << endl; //echo print
    ss.clear(); //repairs stream
    ss.str(line); //erases ss and files with line
    ss >> id; //gives next int in line
    ss.ignore(); //ignores one character
    getline(ss, name, ','); //getline stops at ','
    cout << id << " " << name << endl;

    count = 0;
    sum = 0;
    while(ss >> n){
      count++;
      sum += n;
      if(count == 1){
        min = max = n;
      }
      if(max < n){
        max = n;
      }
      if(min > n){
        min = n;
      }
    }
    if(count > 0){
      avg = static_cast<double>(sum) / static_cast<double>(count);
      cout << "Count = " << count << endl;
      cout << "Sum = " << sum << endl;
      cout << "Average = " << avg << endl;
      cout << "Min = " << min << endl;
      cout << "Max = " << max << endl;
    }
    else{
      cout << "No Data";
    }
  }
  inputFile.close();

  return 0;
}
