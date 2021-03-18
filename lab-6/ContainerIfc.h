//
// Created by Aars Matthew on 7/29/20.
//

#ifndef MYARRAY_CONTAINERIFC_H
#define MYARRAY_CONTAINERIFC_H

#include <string>

using namespace std;

class BADINDEX{};

template <class T>
class ContainerIfc {
public:
    virtual ContainerIfc<T>& pushBack(T) = 0;
    virtual ContainerIfc<T>& popBack(T &) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual T& operator[](int) = 0;
    virtual string toString() = 0;
};

#endif //MYARRAY_CONTAINERIFC_H
