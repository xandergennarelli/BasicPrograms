/*
* Author: Xander Gennarelli
* Assignment Title: My Functions
* Assignment Description:
*           A program that implements some 'useful' math functions using
*                 separate driver, implementation, and header files.
* Due Date: 10/30/2020
* Date Created: 10/28/2020
* Date Last Modified: 10/28/2020
*/
#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <iostream>
#include <cassert>
using namespace std;

//*****************************************************************************
// description: Returns the value of the larger of two integers.
// return: integer
// precondition: two integer values exist
// postcondition: The value of the largest integer is returned.
//                The original integers are unchanged.
//                If the integers have the same value, that value is returned.
//*****************************************************************************
int max(int, int);

//*****************************************************************************
// description: Returns the value of the larger of two doubles.
// return: double
// precondition: two double values exist
// postcondition: The value of the largest double is returned.
//                The original doubles are unchanged.
//                If the doubles have the same value, that value is returned.
//*****************************************************************************
double max(double, double);

//*****************************************************************************
// description: Returns the value of the largest integer in an array.
// return: integer
// precondition: an array of integer values exists
// postcondition: The largest value in the array is returned.
//                The original array is unchanged.
//*****************************************************************************
int max(int m[], int n);

//*****************************************************************************
// description: Returns the value of the largest double in an array.
// return: double
// precondition: an array of double values exists
// postcondition: The largest value in the array is returned.
//                The original array is unchanged.
//*****************************************************************************
double max(double m[], int n);

//*****************************************************************************
// description: Returns the value of the smaller of two integers.
// return: integer
// precondition: two integer values exist
// postcondition: The value of the smallest integer is returned.
//                The original integers are unchanged.
//                If the integers have the same value, that value is returned.
//*****************************************************************************
int min(int, int);

//*****************************************************************************
// description: Returns the value of the smaller of two doubles.
// return: double
// precondition: two double values exist
// postcondition: The value of the smallest double is returned.
//                The original doubles are unchanged.
//                If the doubles have the same value, that value is returned.
//*****************************************************************************
double min(double, double);

//*****************************************************************************
// description: Returns the value of the smallest double in an array.
// return: double
// precondition: an array of double values exists
// postcondition: The smallest value in the array is returned.
//                The original array is unchanged.
//*****************************************************************************
int min(int m[], int n);

//*****************************************************************************
// description: Returns the value of the smallest double in an array.
// return: double
// precondition: an array of double values exists
// postcondition: The smallest value in the array is returned.
//                The original array is unchanged.
//*****************************************************************************
double min(double m[], int n);

//*****************************************************************************
// description: Returns the absolute value of an integer.
// return: integer
// precondition: Some integer value exists.
// postcondition: Integer value is unchanged.
//*****************************************************************************
int absoluteValue(int);

//*****************************************************************************
// description: Returns the absolute value of an double.
// return: double
// precondition: Some double value exists.
// postcondition: Double value is unchanged.
//*****************************************************************************
double absoluteValue(double);

//*****************************************************************************
// description: Calculates factorial.
// return: double
// precondition: Some integer value N exists.
// postcondition: The value of N is unchanged.
//*****************************************************************************
double factorial(int);

//*****************************************************************************
// description: Calculates the number of combinations of M items taken N at
//                    a time.
// return: double
// precondition: Two integer values M and N exist.
// postcondition: The value of M and N are unchanged.
//*****************************************************************************
double combination(int M, int N);

//*****************************************************************************
// description: Calculates the number of permutations of M items taken N at
//                    a time.
// return: double
// precondition: Two integer values M and N exist.
// postcondition: The value of M and N are unchanged.
//*****************************************************************************
double permutation(int M, int N);

#endif //MYFUNCTIONS_H
