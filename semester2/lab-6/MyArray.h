//Xander Gennarelli

#ifndef MYARRAY_H
#define MYARRAY_H

#include "ContainerIfc.h"
#include <sstream>

using namespace std;

template <class T>
class MyArray : public ContainerIfc<T> {
private:
   T* data;
   int capacity, size;
public:
   MyArray();
   MyArray(const MyArray<T>&);
   ~MyArray();
   MyArray& operator = (const MyArray<T>&);
   ContainerIfc<T>& pushBack(T);
   ContainerIfc<T>& popBack(T &);
   int getSize();
   bool isEmpty();
   T& operator[](int);
   string toString();
};

template <class T>
MyArray<T>::MyArray(){
   this->capacity = 5;
   this->size = 0;
   this->data = new T[5];
}

template <class T>
MyArray<T>::MyArray(const MyArray<T>& other){
   this->capacity = other.capacity;
   this->size = other.size;
   this->data = new T[this->capacity];
   for (int i = 0; i < this->size; i++){
      this->data[i * sizeof(T)] = other.data[i * sizeof(T)];
   }
}

template <class T>
MyArray<T>::~MyArray(){
   delete [] this->data;
   data = NULL;
}

template <class T>
MyArray<T>& MyArray<T>::operator = (const MyArray& other){
   this->capacity = other.capacity;
   this->size = other.size;

   delete [] this->data;
   this->data = new T[this->capacity];
   for (int i = 0; i < this->size; i++){
      this->data[i * sizeof(T)] = other.data[i * sizeof(T)];
   }

   return *this;
}

template <class T>
ContainerIfc<T>& MyArray<T>::pushBack(T val){
   if (this->size == this->capacity){
      this->capacity += 5;
      T* newData = new T[this->capacity];
      for (int i = 0; i < this->size; i++){
         newData[i * sizeof(T)] = this->data[i * sizeof(T)];
      }
      delete [] this->data;
      this->data = newData;
      newData = NULL;
   }

   this->data[this->size * sizeof(T)] = val;
   this->size++;

   return *this;
}

template <class T>
ContainerIfc<T>& MyArray<T>::popBack(T &val){
   if (this->size > 0){
      val = this->data[(this->size - 1) * sizeof(T)];
      this->size--;
      if (this->capacity > 5 && static_cast<double>(this->size) / static_cast<double>(this->capacity) > 0.25){
         this->capacity -= 5;
         T* newData = new T[this->capacity];
         for (int i = 0; i < this->size; i++){
            newData[i * sizeof(T)] = this->data[i * sizeof(T)];
         }
         delete [] this->data;
         this->data = newData;
         newData = NULL;
      }
   }

   return *this;
}

template <class T>
int MyArray<T>::getSize(){
   return this->size;
}

template <class T>
bool MyArray<T>::isEmpty(){
   bool out = true;
   if (size > 0) out = false;
   return out;
}

template <class T>
T& MyArray<T>::operator[](int i){
   try{
      if (i > this->size || i < 0) throw BADINDEX();
      return this->data[i * sizeof(T)];
   }
   catch (BADINDEX& e){

   }
}

template <class T>
string MyArray<T>::toString(){
   stringstream ss;
   ss.clear();
   ss << this->size << endl << this->capacity << endl;
   for (int i = 0; i < this->size; i++){
      ss << this->data[i * sizeof(T)] << "\t";
   }
   ss << endl;
   return ss.str();
}

#endif
