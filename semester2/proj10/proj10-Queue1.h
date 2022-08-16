/**
-  file: proj10-Queue1.h
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 10
-  due date: 04/26/2021
-
-  Date Modified: 04/25/2021
-    - File Created
-
-  Implementation of a queue using basic vector functionality.
*/
#ifndef QUEUE1_H
#define QUEUE1_H

#include "proj10-MyVector.h"

template <class T>
class Queue1 : public MyVector<T> {
public:
  void enqueue(T);
  void dequeue(T&); // throws BADINDEX
};

template <class T>
void Queue1<T>::enqueue(T val){
  this->pushBack(val);
}

template <class T>
void Queue1<T>::dequeue(T& val){
  this->popFront(val);
}

#endif
