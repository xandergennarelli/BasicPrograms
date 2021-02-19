#include "proj3-MyString.h"
#include <iostream>
using namespace std;

MyString::MyString(){
  this->size = 0;
  this->capacity = MIN_CAP;
  this->data = new char[MIN_CAP];

  *this->data = '\0';
}

MyString::MyString(const char *str){
  this->size = 0;
  this->capacity = MIN_CAP;
  while (*(str + this->size) != '\0'){
    this->size++;
    if (size+1 > this->capacity) this->capacity *= 2;
  }

  this->data = new char[capacity];

  for (int i = 0; i < this->size; i++){
    this->data[i] = str[i];
  }
  *(this->data + this->size) = '\0';
}

MyString::~MyString(){
  delete [] this->data;
  this->data = NULL;
}

MyString::MyString(const MyString &other){
  this->size = other.size;
  this->capacity = other.capacity;

  this->data = new char[this->capacity];
  for (int i = 0; i < this->size; i++){
    this->data[i] = other.data[i];
  }
  *(this->data + this->size) = '\0';
}



MyString& MyString::operator = (const MyString &other){
  if (this != &other){
    delete [] this->data;

    this->size = other.size;
    this->capacity = other.capacity;

    this->data = new char[this->capacity];
    for (int i = 0; i < this->size; i++){
      this->data[i] = other.data[i];
    }
    *(this->data + this->size) = '\0';
  }
  return *this;
}

bool MyString::operator == (const MyString &other) const{
  bool equal = true;

  if (this->size != other.size) equal = false;
  else{
    for (int i = 0; i < this->size; i++){
      if (*(this->data + i) != *(other.data + 1)) equal = false;
    }
  }

  return equal;
}

char& MyString::operator [ ] (int i){
  char &c = *(this->data + i);
  return c;
}

void MyString::operator += (const MyString &other){
  int newSize = this->size + other.size;
  while (this->size+1 > this->capacity) this->capacity *= 2;

  char *newData = new char[newSize];

  for (int i = 0; i < this->size; i++){
    newData[i] = this->data[i];
  }
  for (int i = 0; i < other.size; i++){
    newData[i + this->size] = other.data[i];
  }
  *(newData + newSize) = '\0';

  delete [] this->data;

  this->size = newSize;
  this->data = newData;
}

MyString MyString::operator + (const MyString &other) const{
  int newSize = this->size + other.size;

  char *newData = new char[newSize];

  for (int i = 0; i < this->size; i++){
    newData[i] = this->data[i];
  }
  for (int i = 0; i < other.size; i++){
    newData[i + this->size] = other.data[i];
  }
  *(newData + newSize) = '\0';

   MyString combinedMS(newData);

   return combinedMS;
}



void MyString::getline(istream& in, char delimit){
  char c;
  int count = 0;
  while (in.peek() != EOF && in.peek() != delimit){
    if (count+2 > this->capacity){
      capacity *= 2;
      char *newData = new char[capacity];
      for (int i = 0; i < count; i++){
        newData[i] = this->data[i];
      }

      delete [] this->data;
      this->data = newData;
    }

    c = in.get();
    *(this->data + count) = c;
    count++;
  }
  this->size = count;
  *(this->data + this->size) = '\0';

  while (this->capacity > MIN_CAP && static_cast<double>(this->size+1)
          / static_cast<double>(this->capacity) < 0.25){
    this->capacity /= 2;
    char *newData = new char[this->capacity];
    for (int i = 0; i < this->size+1; i++){
      newData[i] = this->data[i];
    }

    delete [] this->data;
    this->data = newData;
  }
}

int MyString::length() const{
  return this->size;
}



ostream& operator << (ostream &out, MyString &ms){
  for (int i = 0; i < ms.size; i++){
    out << *(ms.data + i);
  }
  return out;
}
