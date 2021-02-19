#ifndef PROJ3_MYSTRING_H
#define PROJ3_MYSTRING_H

#include <iostream>
using namespace std;

const int MIN_CAP = 10;

class MyString{
private:
  int size;
  int capacity;
  char *data;

public:
  MyString();
  MyString(const char *);
  ~MyString();
  MyString(const MyString &);

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
