/**
-  file: proj5-BUAthlete.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 5
-  due date: 03/15/2021
-
-  Date Modified: 03/12/2021
-    - File Created
-    - Implemtend functions
-
-  Implementation of functions defined in proj5-BUAthlete.hpp
*/

#include "proj5-BUAthlete.hpp"

BUAthlete::BUAthlete(){
  this->athleteID = 0;
  this->athleteName = "no_name";
  this->schoolChoice = "no_school";
  this->athleteLOI = false;
  this->evaluation = 0;
  this->position = OL;
}

BUAthlete::BUAthlete(const BUAthlete& other){
  this->athleteID = other.athleteID;
  this->athleteName = other.athleteName;
  this->schoolChoice = other.schoolChoice;
  this->athleteLOI = other.athleteLOI;
  this->evaluation = other.evaluation;
  this->position = other.position;
}

BUAthlete& BUAthlete::operator = (const BUAthlete& other){
  this->athleteID = other.athleteID;
  this->athleteName = other.athleteName;
  this->schoolChoice = other.schoolChoice;
  this->athleteLOI = other.athleteLOI;
  this->evaluation = other.evaluation;
  this->position = other.position;

  return *this;
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
  out << "Position: ";
  switch (this->position) {
    case OL:
      out << "OL";
      break;
    case QB:
      out << "QB";
      break;
    case RB:
      out << "RB";
      break;
    case WR:
      out << "WR";
      break;
    case TE:
      out << "TE";
      break;
    case DL:
      out << "DL";
      break;
    case DE:
      out << "DE";
      break;
    case LB:
      out << "LB";
      break;
    case CB:
      out << "CB";
      break;
    case S:
      out << "S";
      break;
    default:
      out << "K";
  }
  out << endl;

  return out.str();
}
