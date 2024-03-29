/*
* Author: Xander Gennarelli
* Assignment Title: Letter Grade
* Assignment Description: A program that will take five test scores from the
*                         user and calculate and print the average, letter
*                         grade, minimum grade, maximum grade, median, and
*                         mode.
* Due Date: 9/18/2020
* Date Created: 9/16/2020
* Date Last Modified: 9/17/2020
*/
/*
* Data Abstraction:
*           Creates scores[] to hold each score given by the user.
*           Creates avg, min, max, and median to hold the respective
*                 calculated values.
*           Creates mode[] to hold possible modes if they exist.
*           Creates grade to hold the calculated letter grade.
*           Creates count and maxCount to aid in finding the mode.
* Input:
*           User inputs five scores.
* Process:
*           The average is calculated and used to find the letter grade.
*           The scores are sorted from least to greatest.
*           The min, max, and median scores are found.
*           The modes are found, if they exist.
* Output:
*           Asks the user to enter 5 test scores.
*           If one score is above 100 or below 0, an error message is printed.
*           The scores are echo printed.
*           The average and letter grade are printed.
*           Start extra credit is printed.
*           The minimum grade, maximum grade, and median grade are printed.
*           The mode is printed if it exists, otherwise "No Mode" is printed.
*                 If there are two modes, they are both printed.
*           End extra credit is printed.
* Assumptions:
*           It is assumed that the user will input correctly.
*           It is assumed that the user wants to test exactly 5 scores.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main(){
  //Data Abstraction
  double scores[5], avg, min, max, median;
  double mode[2] = {-1, -1};
  char grade;
  int count, maxCount;

  //Input
  cout << "Please enter 5 test scores:" << endl;
  cin >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4];
  for(int i = 0; i < 5; i++){
    if(scores[i] < 0.0 || scores[i] > 100.0){
      cout << "Error: Bad Data";
      exit(1);
    }
  }

  //Echo print
  cout << "\n" << fixed << setprecision(2) << scores[0] << "\n" << scores[1]
       << "\n" << scores[2] << "\n" << scores[3] << "\n" << scores[4] << endl;

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
  cout << "\n\n*** Start Extra Credit ***\n" << endl;

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

  maxCount = 1;
  for(int i = 0; i < 5; i++){
    count = 0;
    for(int j = 0; j < 5; j++){
      if(fabs(scores[i] - scores[j]) < 0.00001){
        count++;
      }
    }
    if(count > maxCount){
      maxCount = count;
      mode[0] = scores[i];
    }
    else if(count == maxCount && maxCount > 1 &&
            !(fabs(mode[0] - scores[i]) < 0.00001)){
      mode[1] = scores[i];
    }
  }

  cout << "Min = " << min << endl;
  cout << "Max = " << max << endl;
  cout << "Median = " << median << endl;
  if(mode[0] == -1){
    cout << "Mode = No Mode" << endl;
  }
  else if(mode[1] > -1){
    cout << "Mode = " << mode[0] << " " << mode[1] << endl;
  }
  else{
    cout << "Mode = " << mode[0] << endl;
  }

  cout << "\n*** End Extra Credit ***" << endl;

  return 0;
}
