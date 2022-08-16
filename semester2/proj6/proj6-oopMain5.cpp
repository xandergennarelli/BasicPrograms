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
-  A program that stores input data on several types of persons in a file and
-      can search for a specific named person. Uses an OOP implementation.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int PLIST_SIZE = 10;

class Person{
private:
  string name;
  int age;

public:
  string getName(){return name;}
  void readPerson(istream &);
  void writePerson(ostream &);
};

/**
 * readPerson
 *
 * reads the information of a person from the passed istream
 *
 * Parameters:
 *      in: the istream being extracted from
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: in, the istream being extracted from
 */
void Person::readPerson(istream &in){
  getline(in, name);
  in >> age;
  in.ignore(3, '\n');
}

/**
 * writePerson
 *
 * prints the information of a person to the passed ostream
 *
 * Parameters:
 *      out: the ostream being printed to
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: out, the ostream being printed to
 */
void Person::writePerson(ostream &out){
  out << name << endl;
  out << age << endl;
}

class Customer{
private:
  string name;
  int age;
  double shippingRate;

public:
  Customer();
  double getShippingRate();
  string getName(){return name;}
  void readPerson(istream &);
  void writePerson(ostream &);
};

Customer::Customer(){
  shippingRate = 5.0;
}

/**
 * getShippingRate
 *
 * returns the shippingRate member value
 *
 * Parameters: none
 *
 * Output:
 *      return: double shippingRate
 *      reference parameters: none
 *      stream: none
 */
double Customer::getShippingRate(){
  return shippingRate;
}

/**
 * readPerson
 *
 * reads the information of a person from the passed istream
 *
 * Parameters:
 *      in: the istream being extracted from
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: in, the istream being extracted from
 */
void Customer::readPerson(istream &in){
  getline(in, name);
  in >> age;
  in.ignore(3, '\n');
  in >> shippingRate;
  cin.ignore(3, '\n');
}

/**
 * writePerson
 *
 * prints the information of a person to the passed ostream
 *
 * Parameters:
 *      out: the ostream being printed to
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: out, the ostream being printed to
 */
void Customer::writePerson(ostream &out){
  out << name << endl;
  out << age << endl;
  out << shippingRate << endl;
}

class MegaCustomer{
private:
  string name;
  int age;
  double shippingRate;
public:
  MegaCustomer();
  double getShippingRate();
  string getName(){return name;}
  void readPerson(istream &);
  void writePerson(ostream &);
};

MegaCustomer::MegaCustomer(){
  shippingRate = 0;
}

/**
 * getShippingRate
 *
 * returns the shippingRate member value
 *
 * Parameters: none
 *
 * Output:
 *      return: double shippingRate
 *      reference parameters: none
 *      stream: none
 */
double MegaCustomer::getShippingRate(){
  return shippingRate;
}

/**
 * readPerson
 *
 * reads the information of a person from the passed istream
 *
 * Parameters:
 *      in: the istream being extracted from
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: in, the istream being extracted from
 */
void MegaCustomer::readPerson(istream &in){
  getline(in, name);
  in >> age;
  in.ignore(3, '\n');
}

/**
 * writePerson
 *
 * prints the information of a person to the passed ostream
 *
 * Parameters:
 *      out: the ostream being printed to
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: out, the ostream being printed to
 */
void MegaCustomer::writePerson(ostream &out){
  out << name << endl;
  out << age << endl;
  out << shippingRate << endl;
}

/**
 * requestInfo
 *
 * asks the user for information regarding the passed type of person
 *
 * Parameters:
 *      out: the ostream being printed to
 *      msg: string question to be printed
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: out, the ostream being printed to
 */
void requestInfo(ostream &out, string msg){
  out << msg << endl;
}

/**
 * readAgain
 *
 * asks the user if they want to continue inputing person data
 *
 * Parameters:
 *      out: the ostream being printed to
 *      in: the istream being read from
 *
 * Output:
 *      return: string choice that the user makes
 *      reference parameters: none
 *      stream: out, the ostream being printed to
 *              in, the istream being extracted from
 */
string readAgain(ostream &out, istream &in){
  string choice;

  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');

  return choice;
}

/**
 * findPerson
 *
 * searches through a list of people names to find a person
 *
 * Parameters:
 *      pList: the pointer array of either Person, Customer, or MegaCustomer
 *                type.
 *      name: the string name being searched for
 *
 * Output:
 *      return: the index of the found name or -1 if it is not found
 *      reference parameters: none
 *      stream: none
 */
template <class pType>
int findPerson(pType **pList, string name){
  int pos = -1, index = 0;

  while (pos == -1 && index < PLIST_SIZE){
    if (pList[index]->getName() == name){
      pos = index;
    }
    index++;
  }

  return pos;
}

/**
 * personReadLoop
 *
 * handles the reading and printing of new person data for any of the three
 *    person types. completely handles output file stream.
 *
 * Parameters:
 *      pList: the pointer array of either Person, Customer, or MegaCustomer
 *                type.
 *      pfile: the ifstream that data can be read from
 *      fileRead: bool that determines whether or not data is read from a file
 *      msg: string message used for requestInfo()
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: pfile, ifstream used for reading data
 */
template <class pType>
void personReadLoop(pType **pList, ifstream &pfile, bool fileRead, string msg){
  int index = 0;
  string choice = "yes";
  ofstream opfile;
  opfile.open("operson.txt");

  while (choice != "no" && index < PLIST_SIZE){
    if (!fileRead){
      requestInfo(cout, msg);
      pList[index]->readPerson(cin);
      pList[index]->writePerson(opfile);
      choice = readAgain(cout, cin);
    }
    else{
      pList[index]->readPerson(pfile);
      if (!pfile){
        choice = "no";
      }
      else{
        pList[index]->writePerson(opfile);
      }
    }
    index++;
  }

  opfile.close();
}

/**
 * personSearchLoop
 *
 * handles the searching for the named person of any of the three possible types
 *
 * Parameters:
 *      pList: the pointer array of either Person, Customer, or MegaCustomer
 *                type.
 *      choice: string name being searched for in the list of persons
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
template <class pType>
void personSearchLoop(pType **pList, string choice){
  int index;
  if ((index = findPerson(pList, choice)) != -1){
    cout << "Found your person: " << endl;
    pList[index]->writePerson(cout);
  }
  else{
    cout << "Couldn't find your person: " << choice << endl;
  }
}

int main(){
  Person **pList = new Person *[PLIST_SIZE];
  Customer **cList = new Customer *[PLIST_SIZE];
  MegaCustomer **mList = new MegaCustomer *[PLIST_SIZE];
  string choice, pTypeChoice;
  string msg = "Please enter your name followed by your age then shipping rate.";
  bool fileRead = false;
  ifstream pfile;

  cout << "Would you like to read the data from a file (yes/no)? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes"){
    fileRead = true;
    pfile.open("iperson.txt");

    if (!pfile) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }
    pfile >> pTypeChoice;
    pfile.ignore(3, '\n');
  }
  else{
    cout << "What type of Person? (person/customer/mega)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  //allocating memory for each type list
  if (pTypeChoice == "person") {
    for (int i = 0; i < PLIST_SIZE; i++){
      pList[i] = new Person;
    }
    msg = "Please enter your name followed by your age.";
  }
  else if (pTypeChoice == "customer"){
    for (int i = 0; i < PLIST_SIZE; i++){
      cList[i] = new Customer;
    }
  }
  else{
    for( int i = 0; i < PLIST_SIZE; i++ ){
      mList[i] = new MegaCustomer;
    }
  }

  //populates the chosen type list
  if (pTypeChoice == "person"){
    personReadLoop(pList, pfile, fileRead, msg);
  }
  else if (pTypeChoice == "customer"){
    personReadLoop(cList, pfile, fileRead, msg);
  }
  else{
    personReadLoop(mList, pfile, fileRead, msg);
  }
  if (fileRead) pfile.close();

  cout << "Which person are you looking for? " << endl;
  getline(cin, choice);

  //searches the chosen type list
  if (pTypeChoice == "person") {
    personSearchLoop(pList, choice);
    for (int i = 0; i < PLIST_SIZE; i++){
      delete pList[i];
    }
  }
  else if (pTypeChoice == "customer"){
    personSearchLoop(cList, choice);
    for (int i = 0; i < PLIST_SIZE; i++){
      delete cList[i];
    }
  }
  else{
    personSearchLoop(mList, choice);
    for (int i = 0; i < PLIST_SIZE; i++){
      delete mList[i];
    }
  }
  delete [] pList;
  delete [] cList;
  delete [] mList;

  return 0;
}
