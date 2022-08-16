/**
-  file: proj3-MyString.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 3
-  due date: 02/22/2021
-
-  Date Modified: 02/19/2021
-    - File Created
-  Date Modified: 02/22/2021
-    - Added documentation
*/
#include "proj3-MyString.h"

/*
* MyString
*
* This function is the default constructor for the MyString class.
*
* Parameters:
*     none
*
* Output:
*     return: none
*     reference parameters: none
*     streams: none
*/
MyString::MyString(){
  this->size = 0;
  this->capacity = MIN_CAP;
  this->data = new char[MIN_CAP];

  *this->data = '\0';
}

/*
* MyString
*
* This function is the char * parameter constructor for the MyString class.
*
* Parameters:
*     str: the char * to be copied into the MyString's data array.
*
* Output:
*     return: none
*     reference parameters: str, unchanged
*     streams: none
*/
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

/*
* ~MyString
*
* This function is the destructor for the MyString class.
*
* Parameters:
*     none
*
* Output:
*     return: none
*     reference parameters: none
*     streams: none
*/
MyString::~MyString(){
  delete [] this->data;
  this->data = NULL;
}

/*
* MyString
*
* This function is the copy constructor for the MyString class.
*
* Parameters:
*     other: the MyString to be copied.
*
* Output:
*     return: none
*     reference parameters: other, unchanged
*     streams: none
*/
MyString::MyString(const MyString &other){
  this->size = other.size;
  this->capacity = other.capacity;

  this->data = new char[this->capacity];
  for (int i = 0; i < this->size; i++){
    this->data[i] = other.data[i];
  }
  *(this->data + this->size) = '\0';
}


/*
* = operator
*
* This function is the overloaded = operator for the MyString class.
*
* Parameters:
*     other: the MyString this MyString is being assigned as.
*
* Output:
*     return: none
*     reference parameters: other, unchanged
*     streams: none
*/
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

/*
* == operator
*
* This function is the overloaded == operator for the MyString class.
*
* Parameters:
*     other: the MyString this MyString is being compared to.
*
* Output:
*     return: none
*     reference parameters: other, unchanged
*     streams: none
*/
bool MyString::operator == (const MyString &other) const{
  bool equal = true;

  if (this != &other){
    if (this->size != other.size) equal = false;
    else{
      for (int i = 0; i < this->size; i++){
        if (*(this->data + i) != *(other.data + i)) equal = false;
      }
    }
  }

  return equal;
}

/*
* [ ] operator
*
* This function is the overloaded [ ] operator for the MyString class.
*
* Parameters:
*     i: the index of the char that is to be accessed.
*
* Output:
*     return: c, the value of the char at i in data
*     reference parameters: none
*     streams: none
*/
char& MyString::operator [ ] (int i){
  char &c = *(this->data + i);
  return c;
}

/*
* += operator
*
* This function is the overloaded += operator for the MyString class.
*
* Parameters:
*     other: the MyString being concatenated to this MyString.
*
* Output:
*     return: none
*     reference parameters: other, unchanged
*     streams: none
*/
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

/*
* + operator
*
* This function is the overloaded + operator for the MyString class.
*
* Parameters:
*     other: the MyString being concatenated to this MyString.
*
* Output:
*     return: combinedMS, the MyString with the combined data values of the
*                 original two MyStrings
*     reference parameters: other, unchanged
*     streams: none
*/
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

   delete [] newData;

   return combinedMS;
}


/*
* getline
*
* This function is reads a single line (until a newline or other specified
*     character) and fills the data of this MyString with that line.
*
* Parameters:
*     in: the istream being read from.
*     delimit: the character that signals the end of a 'line', defaulted to \n.
*
* Output:
*     return: none
*     reference parameters: in
*     streams: in
*/
void MyString::getline(istream& in, char delimit){
  char c;
  int count = 0;
  while ((c = in.get()) != EOF && c != delimit){
    if (count+2 > this->capacity){
      capacity *= 2;
      char *newData = new char[capacity];
      for (int i = 0; i < count; i++){
        newData[i] = this->data[i];
      }

      delete [] this->data;
      this->data = newData;
    }

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

/*
* length
*
* This function is returns the size/length of the char * data in the MyString.
*
* Parameters:
*     none
*
* Output:
*     return: this->size, int number of chars being used in data
*     reference parameters: none
*     streams: none
*/
int MyString::length() const{
  return this->size;
}

/*
* << operator
*
* This function is an overloaded << operator for use with the MyString class.
*
* Parameters:
*     out: the ostream that this MyString's data values are being pushed to.
*     ms: the MyString who's data is being pushed.
*
* Output:
*     return: out, the ostream being used
*     reference parameters: out, the ostream being used
*                           ms, unchanged
*     streams: out, the ostream being used
*/
ostream& operator << (ostream &out, MyString &ms){
  for (int i = 0; i < ms.size; i++){
    out << *(ms.data + i);
  }
  return out;
}
