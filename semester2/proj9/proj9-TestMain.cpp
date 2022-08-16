/**
-  file: proj9-TestMain.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 9
-  due date: 04/12/2021
-
-  Date Modified: 04/10/2021
-    - File Created
-
-  xxx
*/

#include "proj9-MyList.h"
#include <string>
#include <sstream>
using namespace std;

template <class T>
string printList(MyList<T>& list){
  stringstream ss;
  int size = list.getSize();
  ss << size << endl;
  for (int i = 0; i < size; i++){
    ss << list[i] << "\t";
  }
  ss << endl;

  return ss.str();
}

int main(){
  MyList<int> a;
  int x;

  cout << "testing default constructor ::" << endl;
  cout << printList(a) << endl;

  for (int i = 0; i < 5; i++){
    a.pushFront(i);
  }

  cout << "testing pushFront ::" << endl;
  cout << printList(a) << endl;

  for (int i = 5; i < 10; i++){
    a.pushBack(i);
  }

  cout << "testing pushBack ::" << endl;
  cout << printList(a) << endl;

  MyList<int> b;
  b = a;

  cout << "testing copy assignment operator ::" << endl;
  cout << printList(b) << endl;

  MyList<int> c(a);

  cout << "testing copy constructor ::" << endl;
  cout << printList(c) << endl;

  cout << "testing popFront and popBack ::" << endl;
  a.popFront(x);
  cout << x << endl;
  a.popFront(x);
  cout << x << endl;
  a.popBack(x);
  cout << x << endl;
  a.popBack(x);
  cout << x << endl << endl;

  cout << "testing front and back ::" << endl;
  cout << a.front() << " " << a.back() << endl << endl;

  cout << "completing above two tests ::" << endl;
  cout << printList(a) << endl;

  a = a;

  cout << "update test for copy assignment operator ::" << endl;
  cout << printList(a) << endl;

  cout << "testing isEmpty ::" << endl;
  if (a.isEmpty()) cout << "empty" << endl;
  else cout << "not empty" << endl;
  cout << endl;

  a.erase();

  cout << "testing erase ::" << endl;
  cout << printList(a) << endl;

  cout << "testing isEmpty ::" << endl;
  if (a.isEmpty()) cout << "empty" << endl;
  else cout << "not empty" << endl;
  cout << endl;

  cout << "testing BADINDEX throws ::" << endl;
  try{
    a.popBack(x);
    cout << "should not see this message." << endl;
  }
  catch (BADINDEX b){
    cout << "should see this message." << endl;
  }

  try{
    a.popFront(x);
    cout << "should not see this message." << endl;
  }
  catch (BADINDEX b){
    cout << "should see this message." << endl;
  }

  try{
    x = a.front();
    cout << "should not see this message." << endl;
  }
  catch (BADINDEX b){
    cout << "should see this message." << endl;
  }

  try{
    x = a.back();
    cout << "should not see this message." << endl;
  }
  catch (BADINDEX b){
    cout << "should see this message." << endl;
  }

  try{
    x = a[0];
    cout << "should not see this message." << endl;
  }
  catch (BADINDEX b){
    cout << "should see this message." << endl;
  }

  return 0;
}
