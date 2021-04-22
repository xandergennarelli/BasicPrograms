#ifndef QUEUE3_H
#define QUEUE3_H

#include “proj10-MyList.h”

template <class T>
class Queue3 : public MyList<T> {
public:
  void enqueue( T );
  void dequeue( T& ); // throws BADINDEX
};

#endif
