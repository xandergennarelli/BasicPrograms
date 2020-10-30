/*
* Author: Xander Gennarelli
* Assignment Title: My Functions
* Assignment Description:
*           A program that implements some 'useful' math functions using
*                 separate driver, implementation, and header files.
* Due Date: 10/30/2020
* Date Created: 10/28/2020
* Date Last Modified: 10/29/2020
*/
/*
* Data Abstraction:
*           max_t1, max_t2, ..., max_t10 are created to hold test vals for max.
*           min_t1, min_t2, ..., min_t10 are created to hold test vals for min.
* Input:
*           No Input.
* Process:
*           Each function is tested five times, including edge cases.
* Output:
*           If an assertion fails, an error is thrown.
* Assumptions:
*           It is assumed that no integer passed to factorial() will result in
*                 the output exceeding the maximum value of a double.
*/
#include "myFunctions.h"

int main() {
  assert((max(5, 10) == 10));
  assert((max(-3, -6) == -3));
  assert((max(0, 0) == 0));
  assert((max(0, 1) == 1));
  assert((max(-1, -0) == 0));

  assert((max(5.5, 1.7) == 5.5));
  assert((max(-8.3, -3.6) == -3.6));
  assert((max(0.0, 0.0) == 0.0));
  assert((max(0.0, 1.1) == 1.1));
  assert((max(-1.5, -0.0) == 0.0));

  int max_t1[5] = {5,3,-2,4,0};
  assert((max(max_t1, 5) == 5));
  int max_t2[8] = {5,3,-2,4,0,12,2,5};
  assert((max(max_t2, 8) == 12));
  int max_t3[9] = {0,0,0,1,0,0,0,0,12};
  assert((max(max_t3, 8) == 1));
  int max_t4[3] = {-8,-222222,-20};
  assert((max(max_t4, 3) == -8));
  int max_t5[1] = {0};
  assert((max(max_t5, 1) == 0));

  double max_t6[5] = {5.0,3.2,-2.7,4.2,0.0};
  assert((max(max_t6, 5) == 5.0));
  double max_t7[8] = {5.0,3.2,-2.7,4.2,00.0, 12.7,2.2,5.1};
  assert((max(max_t7, 8) == 12.7));
  double max_t8[5] = {0.0,0.0,1.6,0.0,12.2};
  assert((max(max_t8, 4) == 1.6));
  double max_t9[3] = {-8.8,-222222.9,-20.09};
  assert((max(max_t9, 3) == -8.8));
  double max_t10[1] = {-0.0};
  assert((max(max_t10, 1) == 0.0));

  assert((min(5, 10) == 5));
  assert((min(-3, -6) == -6));
  assert((min(0, 0) == 0));
  assert((min(1, 0) == 0));
  assert((min(-1, -0) == -1));

  assert((min(5.5, 1.7) == 1.7));
  assert((min(-8.3, -3.6) == -8.3));
  assert((min(0.0, 0.0) == 0.0));
  assert((min(0.0, -1.1) == -1.1));
  assert((min(1.5, -0.0) == 0.0));

  int min_t1[5] = {5,3,20,4,0};
  assert((min(min_t1, 5) == 0));
  int min_t2[8] = {5,3,-2,4,0,12,-2,5};
  assert((min(min_t2, 8) == -2));
  int min_t3[9] = {0,0,0,1,0,0,-200,200,12};
  assert((min(min_t3, 8) == -200));
  int min_t4[3] = {-8,-222222,-20};
  assert((min(min_t4, 3) == -222222));
  int min_t5[1] = {0};
  assert((min(min_t5, 1) == 0));

  double min_t6[5] = {5.0,3.2,-2.7,4.2,0.0};
  assert((min(min_t6, 5) == -2.7));
  double min_t7[8] = {5.0,3.2,-2.7,4.2,00.0, 12.7,2.2,-5.1};
  assert((min(min_t7, 8) == -5.1));
  double min_t8[5] = {0.0,0.0,-1.6,0.0,-12.2};
  assert((min(min_t8, 4) == -1.6));
  double min_t9[3] = {-8.8,-222222.9,-20.09};
  assert((min(min_t9, 3) == -222222.9));
  double min_t10[1] = {-0.0};
  assert((min(min_t10, 1) == 0.0));

  assert((absoluteValue(10) == 10));
  assert((absoluteValue(-10) == 10));
  assert((absoluteValue(0) == 0));
  assert((absoluteValue(-20000) == 20000));
  assert((absoluteValue(-0) == 0));

  assert((absoluteValue(1.5) == 1.5));
  assert((absoluteValue(-43.4) == 43.4));
  assert((absoluteValue(0.0) == 0.0));
  assert((absoluteValue(-2321.2) == 2321.2));
  assert((absoluteValue(-0.0) == 0.0));

  assert((factorial(4) == 24.0));
  assert((factorial(10) == 3628800.0));
  assert((factorial(0) == 1.0));
  assert((factorial(1) == 1.0));
  assert((factorial(2) == 2.0));

  assert((combination(5,3) == 10.0));
  assert((combination(8,2) == 28.0));
  assert((combination(10,0) == 1.0));
  assert((combination(5,5) == 1.0));
  assert((combination(20,3) == 1140.0));

  assert((permutation(5,3) == 60.0));
  assert((permutation(8,2) == 56.0));
  assert((permutation(10, 0) == 1.0));
  assert((permutation(5,5) == 120.0));
  assert((permutation(20,3) == 6840.0));

  return 0;
}
