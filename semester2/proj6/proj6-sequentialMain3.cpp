/**
-  file: proj6-sequentialMain3.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 6
-  due date: 03/22/2021
-
-  Date Modified: 03/16/2021
-    - File Created
-
-  This program reads information on people from a file or the terminal and
-     stores it in a file and displays to the screen.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  string name, choice;
  int age;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes"){
    fileRead = true;
    pfile.open("iperson.txt");
    if (!pfile){
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }
  }

  opfile.open("operson.txt");

  choice = "yes"; //choice now determines if there are more people to record
  while (choice != "no"){
    if (!fileRead){ //get info from user
      cout << "Please enter your name followed by your age." << endl;

      getline(cin, name);
      cin >> age;
      cin.ignore(3, '\n');

      opfile << name << endl;
      opfile << age << endl;

      cout << "Do you want to read in another person (yes/no)? " << endl;
      cin >> choice;
      cin.ignore(3, '\n');
    }
    else{ //get info from file
      getline(pfile, name);
      pfile >> age;
      pfile.ignore(3, '\n');
      if (!pfile){
        choice = "no";
      }
      else{
        opfile << name << endl;
        opfile << age << endl;
      }
    }
  }

  if (fileRead){
    pfile.close();
  }
  opfile.close();

  return 0;
}
