/**
-  file: proj5-BUAthlete.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 5
-  due date: 03/15/2021
-
-  Date Modified: 03/12/2021
-    - File Created
-
-  Implementation of functions defined in proj5-BUAthlete.hpp
*/

#include "proj5-BUAthlete.hpp"
#include <sstream>

BUAthlete::BUAthlete(){
  this->athleteID = 0;
  this->athleteName = "no_name";
  this->schoolChoice = "no_school";
  this->athleteLOI = false;
  this->evaluation = 0;
  this->position = 0;
}

void BUAthlete::setEvaluation(int eval){
  this->evaluation = eval;
}

void BUAthlete::setPosition(Position pos){
  this->position = pos;
}

int BUAthlete::getEvaluation(){
  return this->evaluation;
}

Position BUAthlete::getPosition(){
  return this->position;
}

string BUAthlete::toString(){
  ostringstream out;

  out << this->NCAAAthlete::toString();
  out << "Evaluation: " << this->evaluation << endl;
  out << "Position: " << this->position << endl;

  return out.str();
}
