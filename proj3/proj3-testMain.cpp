#include "proj3-MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

void fillArray(char *ptrs, string str);

int main(){
  char *str = new char[5];
  strcpy(str, "hello");

  MyString a(str);

  cout << a << endl;

  return 0;
}
