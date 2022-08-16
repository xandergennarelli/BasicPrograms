/**
-  file: proj5-BUAthleteList.hpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 5
-  due date: 03/15/2021
-
-  Date Modified: 03/12/2021
-    - File Created
-    - Defined BUAthleteList class
-
-  Defines the BUAthleteList class.
*/

#ifndef BUATHLETELIST_H
#define BUATHLETELIST_H

#include "proj5-BUAthlete.hpp"

class BUAthleteList {
protected:
  BUAthlete *list;
  int capacity;
  int size;

  /**
   * resizeArray
   *
   * increases the capacity of data member list by 2
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void resizeArray();

public:
  BUAthleteList();
  BUAthleteList(const BUAthleteList& other);
  ~BUAthleteList();

  /**
   * operator =
   *
   * overloaded copy assignment operator for the BUAthleteList class
   *
   * Parameters:
   *      other: reference to the BUAthleteList instance to be copied
   *
   * Output:
   *      return: a reference to a BUAthleteList instance
   *      reference parameters: none
   *      stream: none
   */
  BUAthleteList& operator = (const BUAthleteList& other);

  /**
   * addNCAAAthlete
   *
   * adds a new instance of BUAthlete to data member list with specified values
   *   for base class data members, resizes list if neccesarry
   *
   * Parameters:
   *      id: the int value to be stored in athleteID
   *      name: the string value to be stored in athleteName
   *      loi: the string value to be converted and stored in athleteLOI
   *      school: the string value to be stored in schoolChoice
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void addNCAAAthlete(int id, string name, string loi, string school);

  /**
   * setBUInfo
   *
   * setBUInfo changes the BUAthlete specific values of the BUAthlete instance
   *   at position index in data member list
   *
   * Parameters:
   *      index: the position in data member list where the BUAthlete instance
   *               to be changed is stored
   *      pos: the Position value to be stored in position
   *      eval: the int value to be stored in evaluation
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void setBUInfo(int index, Position pos, int eval);

  /**
   * FindByID
   *
   * performs a binary search of list to find a BUAthlete with given athleteID
   *
   * Parameters:
   *      id: the athleteID being searched for
   *
   * Output:
   *      return: the index in list of the BUAthlete with the matching athleteID
   *                returns -1 if the athlete does not exist
   *      reference parameters: none
   *      stream: none
   */
  int findByID(int id);

  /**
   * sortByID
   *
   * uses a quicksort to order the elements in data member list from smallest to
   *   greatest athleteID value
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void sortByID();

  /**
   * sortByPosition
   *
   * uses a bubblesort to order the elements in data member list from smallest
   *   to greatest position value
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void sortByPosition();

  /**
   * sortByEvaluation
   *
   * uses a quicksort to order the elements in data member list from greatest to
   *   smallest evaluation value
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void sortByEvaluation();

  /**
   * operator []
   *
   * returns a reference to the BUAthlete object at position index in the list
   *   data member
   *
   * Parameters:
   *      index: the position of the returned BUAthlete object reference
   *
   * Output:
   *      return: a reference to a BUAthlete instance from list
   *      reference parameters: none
   *      stream: none
   */
  BUAthlete& operator [] (int index);

  /**
   * toString
   *
   * converts an instance of a BUAthleteList into a string representation
   *
   * Parameters: none
   *
   * Output:
   *      return: a string representation of the object
   *      reference parameters: none
   *      stream: none
   */
  string toString();
};

/**
 * swapBUA
 *
 * swaps the position of two BUAthletes in the passed pointer array
 *
 * Parameters:
 *      list: pointer to an array of BUAthletes where objects being swapped are
 *                stored
 *      a: index in list of the first BUAthlete
 *      b: index in list of the second BUAthlete
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void swapBUA(BUAthlete *list, int a, int b);

/**
 * quicksortByID
 *
 * recursive implementation of quicksort comparing athleteID values
 *
 * Parameters:
 *      list: pointer to an array of BUAthletes being sorted
 *      low: index in list of the low end of a partition
 *      high: index in list of the high end of a partition
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void quicksortByID(BUAthlete *list, int low, int high);

/**
 * partitionByID
 *
 * helper partitioning function for quicksortByID that splits a larger pointer
 *    array into halves around a pivot point and partially sorts it by
 *    athleteID.
 *
 * Parameters:
 *      list: pointer to an array of BUAthletes being sorted
 *      low: index in list of the low end of a partition
 *      high: index in list of the high end of a partition
 *
 * Output:
 *      return: the highest index in the low partition
 *      reference parameters: none
 *      stream: none
 */
int partitionByID(BUAthlete *list, int low, int high);

/**
 * quicksortByEvaluation
 *
 * recursive implementation of quicksort comparing evaluation values
 *
 * Parameters:
 *      list: pointer to an array of BUAthletes being sorted
 *      low: index in list of the low end of a partition
 *      b: index in list of the high end of a partition
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void quicksortByEvaluation(BUAthlete *list, int low, int high);

/**
 * partitionByEvaluation
 *
 * helper partitioning function for quicksortByEvaluation that splits a larger
 *    pointer array into halves around a pivot point and partially sorts it by
 *    evaluation.
 *
 * Parameters:
 *      list: pointer to an array of BUAthletes being sorted
 *      low: index in list of the low end of a partition
 *      high: index in list of the high end of a partition
 *
 * Output:
 *      return: the highest index in the low partition
 *      reference parameters: none
 *      stream: none
 */
int partitionByEvaluation(BUAthlete *list, int low, int high);

#endif
