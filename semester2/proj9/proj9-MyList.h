/**
-  file: proj9-MyList.h
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 9
-  due date: 04/12/2021
-
-  Date Modified: 04/10/2021
-    - File Created
-
-  Linked List implementation class.
*/

#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"
#include <cstddef>
#include <iostream>
using namespace std;

template <class T>
class MyList : public ContainerIfc<T> {
	protected:
		Node<T> *head;

	public:
		MyList();
		~MyList();
		MyList(const MyList&);
		MyList<T>& operator = (const MyList&);
		MyList<T>& pushFront(T);
		MyList<T>& pushBack(T);
		MyList<T>& popFront(T&);
		MyList<T>& popBack(T&);
		int getSize();
		bool isEmpty();
		T front();
		T back();
		T& operator [](int);
		void erase();
};

/**
    description: class constructor
    pre-condition: none
    post-condition: head points to NULL
    return: nothing
*/
template <class T>
MyList<T>::MyList(){
  this->head = nullptr;
}

/**
    description: class destructor
    pre-condition: a MyList object exists
    post-condition: all memory allocated to the MyList is deleted
    return: nothing
*/
template <class T>
MyList<T>::~MyList(){
  Node<T> *temp;
  while ((temp = this->head) != nullptr){
    this->head = this->head->next;
    delete temp;
  }
  temp = nullptr;
}

/**
    description: class copy constructor
    pre-condition: a MyList object exists
    post-condition: a copy of the class object n is made
    return: nothing
*/
template <class T>
MyList<T>::MyList(const MyList& other){
  if (other.head != nullptr){
    this->head = new Node<T>(other.head->data);
    Node<T> *temp = other.head->next;
    Node<T> *curr = this->head;
    while (temp != nullptr){
      curr->next = new Node<T>(temp->data);
      curr = curr->next;
      temp = temp->next;
    }
    curr = nullptr;
    temp = nullptr;
  }
  else{
    this->head = nullptr;
  }
}

/**
    description: overloaded assignment operator
    pre-condition: a object exists
    post-condition: the object other is unchanged and *this is an exact copy of
                    other
    return: *this
*/
template <class T>
MyList<T>& MyList<T>::operator = (const MyList& other){
  if (this != &other){
    if (other.head != nullptr){
      this->head = new Node<T>(other.head->data);
      Node<T> *temp = other.head->next;
      Node<T> *curr = this->head;
      while (temp != nullptr){
        curr->next = new Node<T>(temp->data);
        curr = curr->next;
        temp = temp->next;
      }
      temp = nullptr;
      curr = nullptr;
    }
    else{
      this->head = nullptr;
    }
  }

  return *this;
}

/**
    description: store data element value in a new Node and adds the Node to the
                 front of a data structure (MyList)
    pre-condition: a MyList object exists
    post-condition: a new Node has been added to the front of the MyList
    return: a reference to self
*/
template <class T>
MyList<T>& MyList<T>::pushFront(T value){
  if (this->isEmpty()) this->head = new Node<T>(value);
  else{
    Node<T> *temp = this->head;
    this->head = new Node<T>(value);
    this->head->next = temp;
    temp = nullptr;
  }

  return *this;
}

/**
    description: store data element value in a new Node and adds the Node to the
                 rear (end) of a data structure (MyList)
    pre-condition: a MyList object exists
    post-condition: a new data element has been added to the rear (end) of the
                    MyList
    return: a reference to self
*/
template <class T>
MyList<T>& MyList<T>::pushBack(T value){
  if (this->isEmpty()) this->head = new Node<T>(value);
  else{
    Node<T> *temp = this->head;
    while (temp->next != nullptr){
      temp = temp->next;
    }
    temp->next = new Node<T>(value);
    temp = nullptr;
  }

  return *this;
}

/**
    description: removes a data element from the front of the data
                 structure (MyList)
    pre-condition: a object exists
    post-condition: a Node has been removed from the front of the linked MyList
                    pointed to by head, and set value equal to the data of the
                    node removed
    error: if the MyList is empty throw a BADINDEX exception
    return: a reference to self
*/
template <class T>
MyList<T>& MyList<T>::popFront(T& value){
  if (this->isEmpty()) throw BADINDEX();
  Node<T> *temp = this->head;
  value = this->head->data;
  this->head = temp->next;
  delete temp;

  temp = nullptr;
  return *this;
}

/**
    description: removes a data element from the rear (end) of the data
                 structure (MyList)
    pre-condition: a object exists
    post-condition: a Node has been removed from the rear of the linked MyList
                    pointed to by head and set value to the data of the node
                    removed
    error: if the MyList is empty throw a BADINDEX exception
    return: a reference to self
*/
template <class T>
MyList<T>& MyList<T>::popBack(T& value){
  if (this->isEmpty()) throw BADINDEX();
  if (this->head->next == nullptr){
    value = this->head->data;
    delete this->head;
    this->head = nullptr;
  }
  else{
    Node<T> *temp = this->head;
    while (temp->next->next != nullptr){
      temp = temp->next;
    }
    value = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
  }

  return *this;
}

/**
    description: returns the number of Nodes currently in the linked MyList
    pre-condition: a object exists
    post-condition: the linked MyList is unchanged
    return: an integer value representing the number of elements in the MyList
*/
template <class T>
int MyList<T>::getSize(){
  int count = 0;
  if (!this->isEmpty()){
    Node<T> *temp = this->head;
    do{
      count++;
    }while ((temp = temp->next) != nullptr);
  }
  return count;
}

/**
    description: returns true if the list is empty and false otherwise
    pre-condition: a object exists
    post-condition: the object is unchanged
*/
template <class T>
bool MyList<T>::isEmpty(){
  return (this->head == nullptr);
}

/**
    description: returns a copy of the first data item in the linked list
    pre-condition: a object exists
    post-condition: the object is unchanged
    error: throw BADINDEX if the linked MyList is empty
*/
template <class T>
T MyList<T>::front(){
  if (this->isEmpty()) throw BADINDEX();
  return this->head->data;
}

/**
    description: returns a copy of the last data item in the linked list
    pre-condition: a object exists
    post-condition: the object is unchanged
    error: throw BADINDEX if the linked MyList is empty
*/
template <class T>
T MyList<T>::back(){
  if (this->isEmpty()) throw BADINDEX();
  Node<T> *temp = this->head;
  while (temp->next != nullptr){
    temp = temp->next;
  }
  T value = temp->data;

  temp = nullptr;
  return value;
}

/**
    description: returns a reference to data element index in the linked list
    pre-condition: a object exists
    post-condition: the object is unchanged
    error: throw BADINDEX if index >= currentSize or n < 0
*/
template <class T>
T& MyList<T>::operator [] (int index){
  if (index >= this->getSize() || index < 0) throw BADINDEX();
  Node<T> *temp = this->head;
  for (int i = 0; i < index; i++){
    temp = temp->next;
  }
  T& value = temp->data;
  temp = nullptr;

  return value;
}

/**
    description: removes all nodes from MyList
    pre-condition: a object exists
    post-condition: the object is an empty MyList
*/
template <class T>
void MyList<T>::erase(){
  if (!this->isEmpty()){
    Node<T> *temp;
    while ((temp = this->head) != nullptr){
      this->head = this->head->next;
      delete temp;
    }
    temp = nullptr;
  }
}
