#ifndef QUEUE1_H
#define QUEUE1_H

#include “proj10-MyVector.h”

template <class T>
class Queue1 : public MyVector<T> {
public:
  void enqueue(T);
  void dequeue(T&); // throws BADINDEX
};

#endif
