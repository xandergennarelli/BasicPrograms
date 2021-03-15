/**
-  file: proj5-testmain.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 5
-  due date: 03/15/2021
-
-  Date Modified: 03/14/2021
-    - Tests Created
-  Date Modified: 03/12/2021
-    - File Created
-
-  Tests all written functions independently.
*/

#include "proj5-BUAthleteList.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(){
  BUAthlete a = BUAthlete();
  BUAthlete b = BUAthlete();

  cout << "Default BUAthlete \"a\": should have id=0, name=no_name, Available, "
       << "Evaluation=0, Position=OL :: " << endl << a.toString() << endl;

  b.setID(1111);
  b.setName("jimmy");
  b.setSchool("SMU");
  b.setLOI("yes");
  b.setEvaluation(8);
  b.setPosition(RB);
  cout << "after using all setters, BUAthlete \"b\": should have id=1111, "
       << "name=jimmy, school=SMU, Evaluation=8, Position=RB :: " << endl
       << b.toString() << endl;

  a = b;
  cout << "after a = b, \"a\": should have id=1111, name=jimmy, school=SMU, "
       << "Evaluation=8, Position=RB :: " << endl << a.toString() << endl;

  BUAthlete c = BUAthlete(b);
  cout << "BUAthlete c is copy constructed from b, \"c\": should have id=1111, "
       << "name=jimmy, school=SMU, Evaluation=8, Position=RB :: "
       << endl << c.toString() << endl;

  BUAthleteList list = BUAthleteList();
  list.addNCAAAthlete(2020, "steven", "no", "baylor");
  cout << "created new BUAthleteList and added athlete, should have: id=2020, "
       << "name=steven, school=baylor, Evaluation=0, Position=OL ::" << endl
       << list.toString() << endl;

  list.setBUInfo(0, RB, 7);
  cout << "added BU info, should have: id=2020, name=steven, school=baylor, "
       << "Evaluation=7, Position=RB ::" << endl << list.toString() << endl;

  list.addNCAAAthlete(2106, "michael", "yes", "UT");
  list.addNCAAAthlete(2019, "amanda", "no", "japan");
  list.setBUInfo(1,QB,7);
  list.setBUInfo(2,RB,9);
  cout << "added two more athletes :: " << endl << list.toString() << endl;

  list.sortByID();
  cout << "after sorting by id ::" << endl << list.toString() << endl;

  cout << "find by id: 2106, should get 2 :: " << list.findByID(2106) << endl;
  cout << "find by id: 2019, should get 0 :: " << list.findByID(2019) << endl;

  list.sortByEvaluation();
  cout << "after sorting by evaluation ::" << endl << list.toString() << endl;

  list.sortByPosition();
  cout << "after sorting by Position ::" << endl << list.toString() << endl;

  cout << "printing athlete at index 1 ::" << endl << list[1].toString() << endl;
  cout << "printing athlete at index 2 ::" << endl << list[2].toString() << endl;

  return 0;
}
