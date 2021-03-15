/**
-  file: proj5-BUAthleteList.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 5
-  due date: 03/15/2021
-
-  Date Modified: 03/14/2021
-    - Implemented remaining functions
-  Date Modified: 03/12/2021
-    - File Created
-    - Implemented Big Four
-
-  Implementation of functions defined in proj5-BUAthleteList.hpp
*/

#include "proj5-BUAthleteList.hpp"
#include <sstream>
#include <iostream>

using namespace std;

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

void BUAthleteList::resizeArray(){
  this->capacity += 2;
  BUAthlete *newList = new BUAthlete[this->capacity];
  for (int i = 0; i < this->size; i++){
    newList[i] = list[i];
  }
  delete [] list;
  list = newList;
}

void BUAthleteList::addNCAAAthlete(int id, string name, string loi, string school){
  BUAthlete newAthlete = BUAthlete();
  newAthlete.setID(id);
  newAthlete.setName(name);
  newAthlete.setLOI(loi);
  newAthlete.setSchool(school);

  if (this->size == this->capacity) this->resizeArray();

  *(this->list + this->size) = newAthlete;
  this->size++;
}

void BUAthleteList::setBUInfo(int index, Position pos, int eval){
  (this->list + index)->setPosition(pos);
  (this->list + index)->setEvaluation(eval);
}

int BUAthleteList::findByID(int id){
  int index = -1, start = 0, end = this->size-1, mid, midID;
  while (start <= end && index == -1){
    mid = start + (end - start) / 2;
    midID = (this->list + mid)->getID();

    if (midID == id) index = mid;
    else if (midID > id) end = mid - 1;
    else start = mid + 1;
  }
  return index;
}

void BUAthleteList::sortByID(){
  quicksortByID(this->list, 0, size-1);
}

void BUAthleteList::sortByPosition(){
  for (int i = 0; i < this->size-1; i++){
    for (int j = 0; j < this->size-i-1; j++){
      if ((this->list + j)->getPosition() > (this->list + j+1)->getPosition()){
        swapBUA(list, j, j+1);
      }
    }
  }
}

void BUAthleteList::sortByEvaluation(){
  quicksortByEvaluation(this->list, 0, size-1);
}

BUAthlete& BUAthleteList::operator [] (int index){
  return this->list[index];
}

string BUAthleteList::toString(){
  ostringstream out;

  for (int i = 0; i < this->size; i++){
    out << "[" << i << "]" << endl;
    out << (this->list + i)->toString();
  }

  return out.str();
}

void swapBUA(BUAthlete *list, int a, int b){
  BUAthlete temp;
  temp = *(list + a);
  list[a] = list[b];
  *(list + b) = temp;
}

void quicksortByID(BUAthlete *list, int low, int high){
  if (low < high){
    int mid = partitionByID(list, low, high);

    quicksortByID(list, low, mid);
    quicksortByID(list, mid+1, high);
  }
}

int partitionByID(BUAthlete *list, int low, int high){
  int mid, pivot;
  bool done;
  BUAthlete *temp;

  mid = low + (high - low) / 2;
  pivot = (list + mid)->getID();

  while (!done){
    while ((list + low)->getID() < pivot) low++;
    while ((list + high)->getID() > pivot) high--;

    if (low >= high) done = true;
    else {
      swapBUA(list, low, high);

      low++;
      high--;
    }
  }
  return high;
}

void quicksortByEvaluation(BUAthlete *list, int low, int high){
  if (low < high){
    int mid = partitionByEvaluation(list, low, high);

    quicksortByEvaluation(list, low, mid);
    quicksortByEvaluation(list, mid+1, high);
  }
}

int partitionByEvaluation(BUAthlete *list, int low, int high){
  int mid, pivot;
  bool done;
  BUAthlete *temp;

  mid = low + (high - low) / 2;
  pivot = (list + mid)->getEvaluation();

  while (!done){
    while ((list + low)->getEvaluation() > pivot) low++;
    while ((list + high)->getEvaluation() < pivot) high--;

    if (low >= high) done = true;
    else {
      swapBUA(list, low, high);

      low++;
      high--;
    }
  }
  return high;
}
