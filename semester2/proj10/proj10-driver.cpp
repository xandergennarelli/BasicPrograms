/**
-  file: proj10-driver.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 10
-  due date: 04/26/2021
-
-  Date Modified: 04/25/2021
-    - File Created
-
-  Driver file for project 10.
*/
#include "proj10-Queue1.h"
#include "proj10-Queue2.h"
#include "proj10-Queue3.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int NUM_VALS = 100;

template <class T>
double timeTrial(T&);

int main(){
  Queue1<int> q1;
  Queue2<int> q2;
  Queue3<int> q3;
  double timeQ1, timeQ2, timeQ3;

  srand(time(0));
  for (int i = 0; i < NUM_VALS; i++){
    q1.enqueue(rand());
    q2.enqueue(rand());
    q3.enqueue(rand());
  }

  timeQ1 = timeTrial(q1);
  timeQ2 = timeTrial(q2);
  timeQ3 = timeTrial(q3);

  cout << "time to dequeue " << NUM_VALS << " ints ::" << endl;
  cout << "Queue1 : " << timeQ1 << "s" << endl;
  cout << "Queue2 : " << timeQ2 << "s" << endl;
  cout << "Queue3 : " << timeQ3 << "s" << endl;

  return 0;
}

template <class T>
double timeTrial(T& q){
  double startTime, endTime;
  int tmp;

  startTime = time(0);
  for (int i = 0; i < NUM_VALS; i++){
    q.dequeue(tmp);
  }
  endTime = time(0);

  return endTime - startTime;
}
