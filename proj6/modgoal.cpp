// oopMain2.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int PLIST_SIZE = 10;

class Person {
protected:
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

void requestInfo( ostream &out, string msg ) {
  out << msg << endl;
}

string readAgain( ostream &out, istream &in ) {
  string choice;

  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');

  return choice;
}

class Customer : public Person {
protected:
  double shippingRate;

public:
  Customer();
  double getShippingRate();
  void readPerson( istream & );
  void writePerson( ostream & );
};

Customer::Customer() {
  shippingRate = 5.0;
}

double Customer::getShippingRate() {
  return shippingRate;
}

void Customer::readPerson( istream & in ) {
  Person::readPerson(in);
  in >> shippingRate;
  cin.ignore(3, '\n');
}

void Customer::writePerson( ostream & out ) {
  Person::writePerson(out);
  out << shippingRate << endl;
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

int findCustomer( Customer pList[], string name ) {
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
  Customer cList[PLIST_SIZE];
  string choice, pTypeChoice;
  int index = 0;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file (yes/no)? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes") {
    fileRead = true;
    pfile.open("iperson.txt");
    if (!pfile) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }

    pfile >> pTypeChoice;
    pfile.ignore(3, '\n');
  } else {
    cout << "What type of Person? (person/customer)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  if( pTypeChoice == "person" ) {
    opfile.open("operson.txt");
    choice = "yes";

    if (fileRead) {
      pList[index].readPerson(pfile);
      if (!pfile) {
        choice = "no";
      }
    }

    while (choice != "no" && index < PLIST_SIZE) {
      if (!fileRead) {
        requestInfo(cout, "Please enter your name followed by your age.");
        pList[index].readPerson(cin);
      }

      pList[index].writePerson(opfile);

      index++;
      if (!fileRead) {
        choice = readAgain(cout, cin);
      } else {
        pList[index].readPerson(pfile);
        if (!pfile) {
          choice = "no";
        }
      }
    }

    if (fileRead) {
      pfile.close();
    }
    opfile.close();

    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);

    if ((index = findPerson(pList, choice)) != -1) {
      cout << "Found your person: " << endl;
      pList[index].writePerson(cout);
    } else {
      cout << "Couldn't find your person: " << choice << endl;
    }
  } else {
    opfile.open("ocustomer.txt");
    choice = "yes";

    if (fileRead) {
      cList[index].readPerson(pfile);
      if (!pfile) {
        choice = "no";
      }
    }

    while (choice != "no" && index < PLIST_SIZE) {
      if (!fileRead) {
        requestInfo(cout, "Please enter your name followed by your age then shipping rate");
        cList[index].readPerson(cin);
      }

      cList[index].writePerson(opfile);

      index++;
      if (!fileRead) {
        choice = readAgain(cout, cin);
      } else {
        cList[index].readPerson(pfile);
        if (!pfile) {
          choice = "no";
        }
      }
    }

    if (fileRead) {
      pfile.close();
    }
    opfile.close();

    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);

    if ((index = findCustomer(cList, choice)) != -1) {
      cout << "Found your person: " << endl;
      cList[index].writePerson(cout);
    } else {
      cout << "Couldn't find your person: " << choice << endl;
    }
  }

  return 0;
}
