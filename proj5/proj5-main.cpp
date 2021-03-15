/**
-  file: proj5-main.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 5
-  due date: 03/15/2021
-
-  Date Modified: 03/14/2021
-    - File Created
-
-  A program to read and store data on potential student athletes, sort the
-     data, and present the two best athletes for each football position.
*/

#include "proj5-BUAthleteList.hpp"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * stoPos
 *
 * Converts a passed string into a Position value.
 *
 * Parameters:
 *      s: copy of a string to be converted to Position
 *
 * Output:
 *      return: Position value that was represented by the passed string
 *      reference parameters: none
 *      stream: none
 */
Position stoPos(string s);

int main(){
  BUAthleteList list = BUAthleteList();
  ifstream inFS;
  stringstream ss;
  int id, index, eval, displayCount = 0, list_size = 0;
  string line, name, loi, school, posStr;
  Position pos;

  inFS.open("proj5-NCAAAthlete.csv");
  if (!inFS){ //ensure first file has opened
    cout << "Error: file not open." << endl;
    exit(1);
  }

  while (getline(inFS, line)){
    ss.clear();
    ss.str(line);

    ss >> id;
    ss.ignore(); //skip comma after the int
    getline(ss, name, ',');
    getline(ss, loi, ',');
    getline(ss, school, ',');

    list.addNCAAAthlete(id, name, loi, school);
    list_size++; //keep track of size of BUAthleteList
  }
  inFS.close();

  list.sortByID();

  inFS.open("proj5-BUAthlete.csv");
  if (!inFS){ //ensure second file has opened
    cout << "Error: file not open." << endl;
    exit(1);
  }

  while (getline(inFS, line)){
    ss.clear();
    ss.str(line);

    ss >> id;
    ss.ignore();
    getline(ss, posStr, ',');
    pos = stoPos(posStr); //convert string to Position
    ss >> eval;

    index = list.findByID(id); //returns -1 if id is not found
    if (index != -1) list.setBUInfo(index, pos, eval);
  }
  inFS.close();

  list.sortByEvaluation();
  list.sortByPosition();

  pos = list[0].getPosition();
  for (int i = 0; i < list_size; i++){
    if (pos != list[i].getPosition()){ // when the next position group is being
      pos = list[i].getPosition();     // checked and printed
      displayCount = 0;
      cout << endl;
    }

    if (displayCount < 2){ // only print two athletes per position
      cout << list[i].toString();
    }

    displayCount++;
  }

  return 0;
}

Position stoPos(string s){
  Position p;
  if (s == "OL") p = OL;
  else if (s == "QB") p = QB;
  else if (s == "RB") p = RB;
  else if (s == "WR") p = WR;
  else if (s == "TE") p = TE;
  else if (s == "DL") p = DL;
  else if (s == "DE") p = DE;
  else if (s == "LB") p = LB;
  else if (s == "CB") p = CB;
  else if (s == "S") p = S;
  else p = K;

  return p;
}
