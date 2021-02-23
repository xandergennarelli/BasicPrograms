/**
-  file: proj3-MyString.h
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 3
-  due date: 02/22/2021
-
-  Date Modified: 02/19/2021
-    - File Created
*/
#ifndef PROJ3_MYSTRING_H
#define PROJ3_MYSTRING_H

#include <iostream>
using namespace std;

const int MIN_CAP = 10; //minimum capacity for a MyString data array.

class MyString{
private:
  int size;
  int capacity;
  char *data;

public:
  MyString();
  MyString(const char *);
  ~MyString();
  MyString(const MyString&);

  MyString& operator = (const MyString&);
  bool operator == (const MyString&) const;
  char& operator [ ] (int);
  void operator += (const MyString&);
  MyString operator + (const MyString&) const;

  void getline(istream&, char delimit = '\n');
  int length() const;

  friend ostream& operator << (ostream&, MyString&);
};

#endif
