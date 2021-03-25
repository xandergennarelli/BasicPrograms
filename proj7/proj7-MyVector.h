/**
-  file: proj7-MyVector.h
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 7
-  due date: 03/29/2021
-
-  Date Modified: 03/24/2021
-    - File Created
-    - Implemented functions and added documentation
-
-  xxx
*/

#include "proj7-ContainerIfc.h"
#include <cstddef>
using namespace std;

template <class T>
class MyVector : public ContainerIfc<T> {
private:
  T *data;
  int size;
  int capacity;
  void grow();
  void shiftRight();
  void shiftLeft();

public:
  MyVector();
  ~MyVector();
  MyVector(const MyVector&);
  MyVector<T>& operator = (const MyVector&);
  MyVector<T>& pushFront(T);
  MyVector<T>& pushBack(T);
  MyVector<T>& popFront(T&); // throws BADINDEX
  MyVector<T>& popBack(T&); // throws BADINDEX
  T front(); // throws BADINDEX
  T back(); // throws BADINDEX
  T& operator [] (int); // throws BADINDEX
  int getSize();
  bool isEmpty();
  void erase();
};

/**
- description: increases the capacity of data by doubling the previous value and allocating the appropriate memory for data
- pre-condition: a MyVector object exists
- post-condition: capacity’s value is doubled and data points to an array of size capacity
- return: nothing
*/
template <class T>
void MyVector<T>::grow(){
  this->capacity *= 2;
  T *newData = new T[this->capacity];
  for (int i = 0; i < this->size; i++){
    newData[i] = this->data[i];
  }

  delete [] data;
  data = newData;
  newData = nullptr;
}

/**
- description: shifts all values in the array one space to the right
- pre-condition: a MyVector object exists
- post-condition: all values are shifted to the right (opens up one space at the beginning of the array)
- return: nothing
*/
template <class T>
void MyVector<T>::shiftRight(){
  for (int i = this->size; i > 0; i--){
    this->data[i] = this->data[i-1];
  }
}

/**
- description: shifts all values in the array one space to the left
- pre-condition: a MyVector object exists
- post-condition: all values are shifted to the left (removes first value from the array)
- return: nothing
*/
template <class T>
void MyVector<T>::shiftLeft(){
  for (int i = 0; i < this->size; i++){
    this->data[i] = this->data[i+1];
  }
}

/**
- description: class constructor
- pre-condition: none
- post-condition: n class object created with size = 0 ,capacity = 10, data points to an array of size capacity and type T
- return: nothing
*/
template <class T>
MyVector<T>::MyVector(){
  this->size = 0;
  this->capacity = 10;
  this->data = new T[this->capacity];
}

/**
- description: class destructor
- pre-condition: a MyVector object exists
- post-condition: all memory allocated to the MyVector is deleted
- return: nothing
*/
template <class T>
MyVector<T>::~MyVector(){
  delete [] data;
  data = nullptr;
}

/**
- description: class copy constructor
- pre-condition: a MyVector object exists
- post-condition: a copy of the class object v is made
- return: nothing
*/
template <class T>
MyVector<T>::MyVector(const MyVector& other){
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new T[this->capacity];
  for (int i = 0; i < this->size; i++){
    this->data[i] = other.data[i];
  }
}

/**
- description: overloaded assignment operator
- pre-condition: a object exists
- post-condition: the object n is unchanged and *this is an exact copy of n
- return: a reference to self
*/
template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& other){
  if (this != &other){
    this->size = other.size;
    this->capacity = other.capacity;

    delete [] this->data;
    this->data = new T[this->capacity];
    for (int i = 0; i < this->size; i++){
      this->data[i] = other.data[i];
    }
  }

  return *this;
}

/**
- description: add data element e to the front of the vector
- pre-condition: a MyVector object exists
- post-condition: if size == capacity, double capacity shift all elements in data to the right data element e has been added to the front of the array, increment size
- return: a reference to self
*/
template <class T>
MyVector<T>& MyVector<T>::pushFront(T item){
  if (this->size >= this->capacity) this->grow();
  this->shiftRight();
  this->data[0] = item;
  this->size++;

  return *this;
}

/**
- description: store data element e in end of the vector
- pre-condition: a MyVector object exists
- post-condition if size == capacity, double capacity data element e has been added to the end of the array, increment size
- return: a reference to self
*/
template <class T>
MyVector<T>& MyVector<T>::pushBack(T item){
  if (this->size >= this->capacity) this->grow();
  this->data[this->size] = item;
  this->size++;

  return *this;
}

/**
- description: removes a data element from the front of the data structure (MyVector)
- pre-condition: a object exists
- post-condition: the first element has been removed from the front of the MyVector, decrement size, and set e equal to the element removed, error if MyVector is empty
- return: a reference to self
*/
template <class T>
MyVector<T>& MyVector<T>::popFront(T& item){
  item = this->data[0];
  this->shiftLeft();
  this->size--;

  return *this;
}

/**
- description: removes a data element from the rear (end) of the data structure (MyVector)
- pre-condition: a object exists
- post-condition: a data element has been removed from the rear of the MyVector, decrement currentSize, and set e equal to the element removed, error if MyVector is empty
- return: a reference to self
*/
template <class T>
MyVector<T>& MyVector<T>::popBack(T& item){
  if (this->size <= 0) throw BADINDEX();
  this->size--;
  item = this->data[this->size];

  return *this;
}

/**
- description: returns a copy of the first data item in the MyVector
- pre-condition: a object exists
- post-condition: the object is unchanged, error if MyVector is empty
- return: a copy of the object at the beginning of the array
*/
template <class T>
T MyVector<T>::front(){
  return this->data[0];
}

/**
- description: returns a copy of the last data item in MyVector
- pre-condition: a object exists
- post-condition: the object is unchanged, error if MyVector is empty
- return: a copy of the object at the end of the array
*/
template <class T>
T MyVector<T>::back(){
  return this->data[this->size - 1];
}

/**
- description: returns a reference to data element n in MyVector
- pre-condition: a object exists
- post-condition: the object is unchanged, error: n >= capacity or n < 0
- return: a reference to the object stored at offset of n within data
*/
template <class T>
T& MyVector<T>::operator [] (int index){
  return this->data[index];
}

/**
- description: returns the number of elements currently in the MyVector
- pre-condition: a object exists
- post-condition: the MyVector is unchanged
- return: an integer value representing the number of elements in the list
*/
template <class T>
int MyVector<T>::getSize(){
  return this->size;
}

/**
- description: returns state information about the list
- pre-condition: a object exists
- post-condition: the MyVector is unchanged
- return: true if the MyVector is empty false otherwise
*/
template <class T>
bool MyVector<T>::isEmpty(){
  return (this->size <= 0);
}

/**
- description: erases a vector
- pre-condition: a object exists
- post-condition: the elements of a MyVector are erased
- return: nothing
*/
template <class T>
void MyVector<T>::erase(){
  this->size = 0;
  this->capacity = 5;

  delete [] this->data;
  this->data = new T[5];
}
