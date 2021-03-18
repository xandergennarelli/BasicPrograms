#include <iostream>
#include "MyArray.h"

using namespace std;

template <class T>
void copyIt(MyArray<T> b) {
    cout << b.toString() << endl;
}

int main() {
    MyArray<int> a;
    int val;

    cout << "Testing default constructor..." << endl;
    cout << "Size: " << a.getSize() << " should be 0" << endl;

    cout << endl << "Testing toString..." << endl;
    cout << a.toString();
    cout << "Should be: \n0\n5\n" << endl;

    cout << "Tesing pushBack()..." << endl;

    for( int i = 0; i < 10; i++ ) {
        a.pushBack(i);
    }

    cout << a.toString();
    cout << "Should be: \n10\n10\n0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n" << endl;

    cout << "Testing copy constructor..." << endl;
    copyIt(a);
    cout << "Should be: \n10\n10\n0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n" << endl;

    cout << "Testing overloaded assignment operator..." << endl;
    MyArray<int> b;
    b = a;
    cout << b.toString() << endl;
    cout << "Should be: \n" << a.toString() << endl;
    b = b;

    cout << "Tesing popBack()..." << endl;
    while( !a.isEmpty() ) {
        a.popBack(val);
        cout << val << "\t";
    }
    cout << endl;
    cout << "Should be: \n9\t8\t7\t6\t5\t4\t3\t2\t1\t0" << endl;

    cout << endl;
    cout << "Update for overloaded assignment operator..." << endl;
    cout << b.toString();
    cout << "Should be different than: " << endl;
    cout << a.toString();

    cout << "Tesing operator[]..." << endl;

    try {
        a[2] = 6;
        cout << "Should not see this message" << endl;
    } catch (BADINDEX) {
        cout << "Should see this message" << endl;
    }

    for( int i = 0; i < 6; i++ ) {
        a.pushBack(i);
    }

    cout << "Starting with..." << endl << a.toString() << endl;

    int x = 5;
    for( int i = 0; i < 6; i ++) {
        a[i] = x--;
    }
    cout << "Now is ..." << endl << a.toString() << endl;

    cout << "Should be... " << endl;
    cout << "6\n10\n5\t4\t3\t2\t1\t0\n";
    return 0;
}
