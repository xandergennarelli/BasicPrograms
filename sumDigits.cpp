/*
* Author: Xander Gennarelli
* Assignment Title: Sum The Digits In An Integer
* Assignment Description: A program that will sum the integers of a three
*                         digit integer and output that sum.
* Due Date: 9/9/2020
* Date Created: 9/2/2020
* Date Last Modified: 9/2/2020
*/

#include <iostream>
using namespace std;

int sum(int num){
  int dig1 = num % 10;
  num /= 10;
  int dig2 = num % 10;
  num /= 10;

  return dig1 + dig2 + num;
}

int main(){
  int num;
  cout << "Enter an integer between 0 and 999: ";
  cin >> num;
  cout << num << endl;

  cout << "The sum of the digits is " << sum(num) << "." << endl;

  return 0;
}
