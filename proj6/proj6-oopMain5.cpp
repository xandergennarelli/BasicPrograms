/**
-  file: proj6-oopMain5.cpp
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

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int PLIST_SIZE = 10;

class Person {
  string name;
  int age;

public:
  string getName() { return name; }
  void readPerson( istream & );
  void writePerson( ostream & );
};

void Person::readPerson( istream &in ) {
  getline( in, name );
  in >> age;
  in.ignore(3, '\n');
}

void Person::writePerson( ostream &out ) {
  out << name << endl;
  out << age << endl;
}

void requestInfo( ostream &out ) {
  out << "Please enter your name followed by your age." << endl;
}

string readAgain( ostream &out, istream &in ) {
  string choice;

  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');

  return choice;
}

int findPerson( Person pList[], string name ) {
  int pos = -1, index = 0;

  while( pos == -1 && index < PLIST_SIZE ) {
    if( pList[index].getName() == name ) {
      pos = index;
    }
    index++;
  }

  return pos;
}

int main() {
  Person pList[PLIST_SIZE];
  string choice;
  int index = 0;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file (yes/no)? " << endl;
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
    pList[index].readPerson( pfile );
    if( !pfile ) {
      choice = "no";
    }
  }

  while( choice != "no" && index < PLIST_SIZE ) {
    if( !fileRead ) {
      requestInfo( cout );
      pList[index].readPerson( cin );
    }

    pList[index].writePerson( opfile );

    index++;
    if( !fileRead ) {
      choice = readAgain( cout, cin );
    } else {
      pList[index].readPerson( pfile );
      if( !pfile ) {
        choice = "no";
      }
    }
  }

  if( fileRead ) {
    pfile.close();
  }
  opfile.close();

  cout << "Which person are you looking for? " << endl;
  getline( cin, choice );

  if( (index = findPerson( pList, choice )) != -1 ) {
    cout << "Found your person: " << endl;
    pList[index].writePerson( cout );
  } else {
    cout << "Couldn't find your person: " << choice << endl;
  }

  return 0;
}
