/**
-  file: proj10-Queue3.h
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 10
-  due date: 04/26/2021
-
-  Date Modified: 04/25/2021
-    - File Created
-
-  Implementation of a queue using basic list functionality.
*/
#ifndef QUEUE3_H
#define QUEUE3_H

#include "proj10-MyList.h"

template <class T>
class Queue3 : public MyList<T> {
public:
  void enqueue(T);
  void dequeue(T&); // throws BADINDEX
};

/**
description: store data element value in a new Node and adds the Node to the
             rear (end) of a queue
pre-condition: a Queue3 object exists
post-condition: a new data element has been added to the rear (end) of the
                queue
return: a reference to self
*/
template <class T>
void Queue3<T>::enqueue(T val){
  this->pushBack(val);
}

/**
description: removes a data element from the front of the queue
pre-condition: a object exists
post-condition: a Node has been removed from the front of the queue
                pointed to by head, and set value equal to the data of the
                node removed
error: if the queue is empty throw a BADINDEX exception
return: void
*/
template <class T>
void Queue3<T>::dequeue(T& val){
  this->popFront(val);
}

#endif
