#ifndef QUEUE2_H
#define QUEUE2_H

#include “proj10-MyVector.h”

template <class T>
class Queue2 : public MyVector<T> {
private:
  int front, rear;

public:
  Queue2();
  void enqueue(T);
  void dequeue(T&); // throws BADINDEX
};

#endif
