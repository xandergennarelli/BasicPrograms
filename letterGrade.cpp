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
#include <iomanip>
using namespace std;

int main(){
  //Data Abstraction
  double scores[5], avg, min, max, median, mode;
  char grade;
  int count, maxCount;

  //Input
  cout << "Please enter 5 test scores:\n" << endl;
  cin >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4];
  if(cin.fail()){
    cout << "Error: Bad Data";
    exit(1);
  }
  //Echo print
  cout << scores[0] << "\n" << scores[1] << "\n" << scores[2] << "\n" << scores[3] << "\n"
       << scores[4] << endl;

  //Process
  avg = (scores[0] + scores[1] + scores[2] + scores[3] + scores[4]) / 5.0;

  if(avg >= 89.5){
    grade = 'A';
  }
  else if(avg >= 79.5){
    grade = 'B';
  }
  else if(avg >= 69.5){
    grade = 'C';
  }
  else if(avg >= 50.5){
    grade = 'D';
  }
  else{
    grade = 'F';
  }

  //Output
  cout << "Average = " << fixed << setprecision(2) << avg << endl;
  cout << "Grade = " << grade << endl;

  //Extra Credit
  cout << "\n*** Start Extra Credit ***\n" << endl;

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 4; j++){
      if(scores[j] > scores[j + 1]){
        double temp = scores[j + 1];
        scores[j + 1] = scores[j];
        scores[j] = temp;
      }
    }
  }
  min = scores[0];
  max = scores[4];
  median = scores[2];

  maxCount = 0;
  for(int i = 0; i < 5; i++){
    count = 0;
    for(int j = 0; j < 5; j++){
      if(fabs(scores[i] - scores[j]) < 0.00001){
        count++;
      }
    }
    if(count >) //how to decide if the count is the greatest
  }

  cout << "Min = " << min << endl;
  cout << "Max = " << max << endl;
  cout << "Median = " << median << endl;
  cout << "Mode = " << mode << endl;

  cout << "\n*** End Extra Credit ***" << endl;

  return 0;
}

/*

Please enter 5 test scores:

88.00
92.00
95.00
100.00
88.00
Average = 92.60
Grade = A


*** Start Extra Credit ***

Min = 88.00
Max = 100.00
Median = 92.00
Mode = 88.00

*** End Extra Credit ***


Please enter 5 test scores:

50.00
40.00
60.00
70.00
20.00
Average = 48.00
Grade = F


*** Start Extra Credit ***

Min = 20.00
Max = 70.00
Median = 50.00
Mode = No Mode

*** End Extra Credit ***


Please enter 5 test scores:
Error: Bad Data
*/
