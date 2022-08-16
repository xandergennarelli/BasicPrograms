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

  cout << "Testing Default MyVector Constructor:" << endl;
  cout << vectorToString(a) << endl;
  cout << "Should Be:" << endl << "10" << endl << "0" << endl
       << endl << endl << endl;

  for (int i = 5; i < 10; i++){
    a.pushBack(i);
  }
  for (int i = 4; i >= 0; i--){
    a.pushFront(i);
  }
  cout << "Testing pushBack and pushFront:" << endl;
  cout << vectorToString(a) << endl;
  cout << "Should Be:" << endl << "10" << endl << "10" << endl
       << "0\t1\t2\t3\t4\t5\t6\t7\t8\t9" << endl << endl << endl;

  a.pushFront(101);
  cout << "Testing grow:" << endl;
  cout << vectorToString(a) << endl;
  cout << "Should Be:" << endl << "20" << endl << "11" << endl
       << "101\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9" << endl << endl << endl;

  int q, r, s;
  a.popBack(q);
  a.popBack(r);
  a.popFront(s);
  cout << "Testing popBack:" << endl;
  cout << q << endl;
  cout << "Should Be:" << endl << "9" << endl << endl;
  cout << r << endl;
  cout << "Should Be:" << endl << "8" << endl << endl << endl;
  cout << "Testing popFront:" << endl;
  cout << s << endl;
  cout << "Should Be:" << endl << "101" << endl << endl << endl;

  cout << "Testing front:" << endl;
  cout << a.front() << endl;
  cout << "Should Be:" << endl << "0" << endl << endl << endl;
  cout << "Testing back:" << endl;
  cout << a.back() << endl;
  cout << "Should Be:" << endl << "7" << endl << endl << endl;

  MyVector<int> b = MyVector<int>(a);
  cout << "Testing Copy Constructor:" << endl;
  cout << vectorToString(b) << endl;
  cout << "Should Be:" << endl << vectorToString(a) << endl << endl << endl;

  b.pushBack(9);
  b.pushFront(8);
  b.pushFront(7);
  a = b;
  cout << "Testing Copy assignment operator:" << endl;
  cout << vectorToString(a) << endl;
  cout << "Should Be:" << endl << vectorToString(b) << endl << endl << endl;

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
