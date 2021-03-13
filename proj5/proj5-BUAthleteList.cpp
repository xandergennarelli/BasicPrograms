/**
-  file: proj5-BUAthleteList.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 5
-  due date: 03/15/2021
-
-  Date Modified: 03/12/2021
-    - File Created
-
-  Implementation of functions defined in proj5-BUAthleteList.hpp
*/

#include "proj5-BUAthleteList.hpp"

BUAthleteList::BUAthleteList(){
  this->list = new BUAthlete[2];
  this->capacity = 2;
  this->size = 0;
}

BUAthleteList::BUAthleteList(const BUAthleteList& other){
  this->list = new BUAthlete[other.capacity];
  this->capacity = other.capacity;
  this->size = other.size;

  for (int i = 0; i < other.size; i++){
    this->list[i] = other.list[i];
  }
}

BUAthleteList::~BUAthleteList(){
  delete [] this->list;
  list = NULL;
}

BUAthleteList& BUAthleteList::operator = (const BUAthleteList& other){
  delete [] this->list;
  this->list = new BUAthlete[other.capacity];
  this->capacity = other.capacity;
  this->size = other.size;

  for (int i = 0; i < other.size; i++){
    this->list[i] = other.list[i];
  }

  return *this;
}
