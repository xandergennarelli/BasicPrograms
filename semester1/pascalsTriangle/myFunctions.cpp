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

#include "myFunctions.h"

int max(int a, int b){
  if (b > a) a = b;
  return a;
}

double max(double a, double b){
  if (b > a) a = b;
  return a;
}

int max(int m[], int n){
  int maxVal;
  for (int i = 0; i < n; i++){
    if (i == 0) maxVal = m[i];
    if (m[i] > maxVal) maxVal = m[i];
  }
  return maxVal;
}

double max(double m[], int n){
  double maxVal;
  for (int i = 0; i < n; i++){
    if (i == 0) maxVal = m[i];
    if (m[i] > maxVal) maxVal = m[i];
  }
  return maxVal;
}

int min(int a, int b){
  if (b < a) a = b;
  return a;
}

double min(double a, double b){
  if (b < a) a = b;
  return a;
}

int min(int m[], int n){
  int minVal;
  for (int i = 0; i < n; i++){
    if (i == 0) minVal = m[i];
    if (m[i] < minVal) minVal = m[i];
  }
  return minVal;
}

double min(double m[], int n){
  double minVal;
  for (int i = 0; i < n; i++){
    if (i == 0) minVal = m[i];
    if (m[i] < minVal) minVal = m[i];
  }
  return minVal;
}

int absoluteValue(int n){
  if (n < 0) n *= -1;
  return n;
}

double absoluteValue(double n){
  if (n < 0.0) n *= -1.0;
  return n;
}

double factorial(int n){
  double f = 1;
  if (n > 0){
    f = static_cast<double>(n);
    for (int i = n - 1; i > 1; i--){
      f *= static_cast<double>(i);
    }
  }
  return f;
}

double combination(int M, int N){
  return permutation(M, N) / factorial(N);
}

double permutation(int M, int N){
  return factorial(M) / factorial(M - N);
}
