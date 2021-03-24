/**
-  file: proj7-MyVector.h
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 7
-  due date: 03/29/2021
-
-  Date Modified: 03/24/2021
-    - File Created
-
-  xxx
*/

#include "proj7-ContainerIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:
  MyVector ();
  ~MyVector ();
  MyVector (const MyVector&);
  MyVector<T>& operator = (const MyVector&);
  MyVector<T>& pushFront(T);
  MyVector<T>& pushBack(T);
  MyVector<T>& popFront(T&);
  MyVector<T>& popBack(T&);
  T  front();
  T  back();
  T&  operator [](int);
  int getSize();
  bool isEmpty();
  void erase();

private:
  T  *data;
  int size;
  int capacity;
  void grow();
  void shiftRight();
  void shiftLeft();
};
