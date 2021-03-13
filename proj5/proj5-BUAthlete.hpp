/**
-  file: proj5-BUAthlete.hpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 5
-  due date: 03/15/2021
-
-  Date Modified: 03/12/2021
-    - File Created
-    - Defined BUAthlete class and enum Position
-
-  Defines the BUAthlete class.
*/

#ifndef BUATHLETE_H
#define BUATHLETE_H

#include "proj5-NCAAAthlete.hpp"

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};

class BUAthlete : public NCAAAthlete {
protected:
  int evaluation;
  Position position;

public:
  BUAthlete();
  BUAthlete(const BUAthlete& other);

  /**
   * operator =
   *
   * overloaded copy assignment operator for the BUAthlete class
   *
   * Parameters:
   *      other: reference to the BUAthlete instance to be copied
   *
   * Output:
   *      return: a reference to a BUAthlete instance
   *      reference parameters: none
   *      stream: none
   */
  BUAthlete& operator = (const BUAthlete& other);

  /**
   * setEvaluation
   *
   * setEvaluation stores the passed parameter in the evaluation data member
   *
   * Parameters:
   *      eval: the number to store in the evaluation data member
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void setEvaluation(int eval);

  /**
   * setPosition
   *
   * setPosition stores the passed parameter in the position data member
   *
   * Parameters:
   *      pos: the enum Position value to store in the position data member
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void setPosition(Position pos);

  /**
   * getEvaluation
   *
   * getEvaluation returns a copy of the evaluation data member
   *
   * Parameters: none
   *
   * Output:
   *      return: a copy of the evaluation data member
   *      reference parameters: none
   *      stream: none
   */
  int getEvaluation();

  /**
   * getPosition
   *
   * getPosition returns a copy of the position data member
   *
   * Parameters: none
   *
   * Output:
   *      return: a copy of the position data member
   *      reference parameters: none
   *      stream: none
   */
  Position getPosition();

  /**
   * toString
   *
   * converts an instance of a BUAthlete into a string representation
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

#endif
