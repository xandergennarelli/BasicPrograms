/*
* Author: Xander Gennarelli
* Assignment Title: Sum The Digits In An Integer
* Assignment Description: A program that will sum the integers of a three
*                         digit integer and output that sum.
* Due Date: 9/9/2020
* Date Created: 9/2/2020
* Date Last Modified: 9/8/2020
*/
/*
* Data Abstraction:
*           Five int variables are created to hold the input, the first two
*                 digits, the sum of the digits, and the product of the digits.
*           One double is created to hold the average of the digits.
* Input:
*           The program reads input in the form of an integer between
*                 0 and 999 and assigns it to the variable num.
* Process:
*           The first two digits is pulled off of the original and placed into
*                 variables leaving the last digit in num.
*           All three digits are added together into sum. If num is less than
*                 three digits the extra digits will be zero.
* Output:
*           Asks the user for a number between 0 and 999.
*           Prints the sum of the digits in the sentence "The sum of the digits
*                 is [sum].".
*           Prints the product of the digits.
*           Prints the average of the digits.
* Assumptions:
*           It is assumed that the user will correctly input data.
*           It is assumed the user will only input one number at a time.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int num;
  int dig1;
  int dig2;
  int sum;
  int prod;
  double avg;


  cout << "Enter an integer between 0 and 999: ";
  cin >> num;
  cout << num << endl; //echo print

  dig1 = num % 10;
  num /= 10;
  dig2 = num % 10;
  num /= 10;
  sum = dig1 + dig2 + num;

  cout << "The sum of the digits is " << sum << "." << endl;

  cout << "\n*** Start Extra Credit ***\n" << endl;

  prod = dig1 * dig2 * num;
  avg = static_cast<double>(sum) / 3.0;

  cout << "Product = " << prod << endl;
  cout << "Average = " << fixed << setprecision(1) << avg << endl;

  cout << "\n*** End Extra Credit ***" << endl;

  return 0;
}
