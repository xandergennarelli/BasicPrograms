/**
-  file: proj6-modularMain3.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 6
-  due date: 03/22/2021
-
-  Date Modified: 03/16/2021
-    - File Created
-
-  ***Description***
*/

//also sequential goal

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readPerson( istream &in, string &name, int &age ) {
  getline( in, name );
  in >> age;
  in.ignore(3, '\n');
}

void requestInfo( ostream &out ) {
  out << "Please enter your name followed by your age." << endl;
}

void writePerson( ostream &out, string name, int age ) {
  out << name << endl;
  out << age << endl;
}

string readAgain( ostream &out, istream &in ) {
  string choice;

  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');

  return choice;
}

int main() {
  string name, choice;
  int age;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if( choice == "yes" ) {
    fileRead = true;
    pfile.open("iperson.txt");
    if( !pfile ) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }
  }

  opfile.open("operson.txt");

  choice = "yes";
  if( fileRead ) {
    readPerson( pfile, name, age );
    if( !pfile ) {
      choice = "no";
    }
  }

  while( choice != "no" ) {
    if( !fileRead ) {
      requestInfo( cout );
      readPerson( cin, name, age );
    }

    writePerson( opfile, name, age );

    if( !fileRead ) {
      choice = readAgain( cout, cin );
    } else {
      readPerson( pfile, name, age );
      if( !pfile ) {
        choice = "no";
      }
    }
  }

  if( fileRead ) {
    pfile.close();
  }
  opfile.close();

  return 0;
}
