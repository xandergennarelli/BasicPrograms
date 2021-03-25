/**
-  file: proj7-TestMain.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 7
-  due date: 03/29/2021
-
-  Date Modified: 03/24/2021
-    - File Created
-
-  Tests each function in proj7-MyVector.h independently.
*/

#include "proj7-MyVector.h"
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
string vectorToString(MyVector<T>&);

int main(){
  MyVector<int> a = MyVector<int>();

  for (int i = 5; i < 10; i++){
    a.pushBack(i);
  }
  for (int i = 4; i >= 0; i--){
    a.pushFront(i);
  }
  cout << vectorToString(a) << endl;

  int q, r, s;
  a.popBack(q);
  a.popBack(r);
  a.popFront(s);
  cout << q << " " << r << endl;
  cout << s << endl;
  cout << a.front() << " " << a.back() << endl << endl;
  cout << vectorToString(a) << endl;

  MyVector<int> b = MyVector<int>(a);
  cout << vectorToString(b) << endl;

  b.pushBack(9);
  b.pushFront(8);
  b.pushFront(7);
  cout << vectorToString(b) << endl;

  cout << vectorToString(a) << endl;
  cout << vectorToString(b) << endl;
  a = b;
  cout << vectorToString(a) << endl;

  for (int i = a.getSize() - 1; i >= 0; i--){
    cout << a[i] << "\t";
  }
  cout << endl << endl;
  cout << a.isEmpty() << endl;
  MyVector<int> c = MyVector<int>();
  cout << c.isEmpty() << endl;
  a.erase();
  cout << a.isEmpty() << endl;

  return 0;
}

template <class T>
string vectorToString(MyVector<T>& v){
  stringstream ss;
  ss << v.getCapacity() << endl;
  ss << v.getSize() << endl;
  for (int i = 0; i < v.getSize(); i++){
    ss << v[i] << "\t";
  }
  ss << endl;

  return ss.str();
}
