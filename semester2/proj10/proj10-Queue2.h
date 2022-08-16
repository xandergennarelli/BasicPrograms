/**
-  file: proj10-Queue2.h
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 10
-  due date: 04/26/2021
-
-  Date Modified: 04/25/2021
-    - File Created
-
-  Implementation of a queue using circular vector functionality.
*/
#ifndef QUEUE2_H
#define QUEUE2_H

#include "proj10-MyVector.h"

template <class T>
class Queue2 : public MyVector<T> {
private:
  int front, rear;

public:
  Queue2();
  void enqueue(T);
  void dequeue(T&); // throws BADINDEX
};

template <class T>
Queue2<T>::Queue2(){
  front = 0;
  rear = 0;
}

template <class T>
void Queue2<T>::enqueue(T val){
  if (this->size >= this->capacity){ // grow circular queue
    this->capacity *= 2;
    T *newData = new T[this->capacity];
    int circIndex = this->front;
    for (int i = 0; i < this->size; i++){
      newData[i] = this->data[circIndex];

      circIndex++;
      if (circIndex >= this->capacity / 2){
        circIndex = 0;
      }
    }
    this->front = 0;
    this->rear = this->size - 1;

    delete [] this->data;
    this->data = newData;
    newData = nullptr;
  }

  this->rear++;
  if (this->rear >= this->capacity){
    this->rear = 0;
  }

  this->data[this->rear] = val;
  this->size++;
}

template <class T>
void Queue2<T>::dequeue(T& val){
  if (this->size <= 0) throw BADINDEX();

  val = this->data[front];

  this->front++;
  if (this->front >= this->capacity){
    this->front = 0;
  }
  this->size--;
}

#endif
