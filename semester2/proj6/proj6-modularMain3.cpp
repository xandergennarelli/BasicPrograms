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
-  This program reads information on people from a file or the terminal and
-     stores it in a file and displays to the screen.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int PLIST_SIZE = 10;

/**
 * readPerson
 *
 * reads the information of a person from the passed istream
 *
 * Parameters:
 *      in: the istream being extracted from
 *      type: string representing the type of person being read
 *      name: string representation of the name of a person
 *      age: int representation of the age of a person
 *      sr: double representation of a shippingRate, only used if the person is
 *            a customer
 *
 * Output:
 *      return: none
 *      reference parameters: name - string name of a person, age - int age of
 *                              a person, sr - double shipping rate of a person
 *      stream: in, the istream being extracted from
 */
void readPerson(istream &in, string type, string &name, int &age, double &sr){
  getline(in, name);
  in >> age;
  in.ignore(3, '\n');
  if (type != "person"){
    in >> sr;
    in.ignore(3, '\n');
  }
}

/**
 * writePerson
 *
 * prints the information of a person to the passed ostream
 *
 * Parameters:
 *      out: the ostream being printed to
 *      type: string representing the type of person being written
 *      name: string representation of the name of a person
 *      age: int representation of the age of a person
 *      sr: double representation of a shippingRate, only used if the person is
 *            a customer
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: out, the ostream being printed to
 */
void writePerson(ostream &out, string type, string name, int age, double sr){
  out << name << endl;
  out << age << endl;
  if (type != "person"){
    out << sr << endl;
  }
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
 *      nameList: the array of string person names being searched
 *      name: the string name being searched for
 *
 * Output:
 *      return: the index of the found name or -1 if it is not found
 *      reference parameters: none
 *      stream: none
 */
int findPerson(string nameList[], string name){
  int pos = -1, index = 0;

  while (pos == -1 && index < PLIST_SIZE){
    if (nameList[index] == name){
      pos = index;
    }
    index++;
  }

  return pos;
}

int main(){
  string name, choice, pTypeChoice, msg;
  string nameList[PLIST_SIZE];
  int age, index = 0, ageList[PLIST_SIZE];
  double shippingRate, srList[PLIST_SIZE];
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file (yes/no)? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes"){
    fileRead = true;
    pfile.open("iperson.txt");
    if (!pfile){
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }

    pfile >> pTypeChoice;
    pfile.ignore(3, '\n');
  }
  else{
    cout << "What type of Person? (person/customer)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  if (pTypeChoice == "person"){ //open file depending on person type
    opfile.open("operson.txt");
    msg = "Please enter your name followed by your age.";
  }
  else{
    opfile.open("ocustomer.txt");
    msg = "Please enter your name followed by your age then shipping rate.";
  }

  choice = "yes"; //choice now represents if the program will add more people

  while (choice != "no" && index < PLIST_SIZE){      //all functions will act as
    if (!fileRead){//if the file is not being read   //needed according to type
      requestInfo(cout, msg);                //of person given
      readPerson(cin, pTypeChoice, nameList[index], ageList[index], srList[index]);
      writePerson(opfile, pTypeChoice, nameList[index], ageList[index], srList[index]);
      choice = readAgain(cout, cin);
    }
    else{//if the file is being read
      readPerson(pfile, pTypeChoice, nameList[index], ageList[index], srList[index]);
      if (!pfile){
        choice = "no";
      }
      else{//filestream is not finished or broken
        writePerson(opfile, pTypeChoice, nameList[index], ageList[index], srList[index]);
      }
    }

    index++;
  }
  if (fileRead){
    pfile.close();
  }
  opfile.close(); //done with file handling

  cout << "Which person are you looking for? " << endl;
  getline(cin, choice);
  if ((index = findPerson(nameList, choice)) != -1){
    cout << "Found your person: " << endl;
    writePerson(cout, pTypeChoice, nameList[index], ageList[index], srList[index]);
  }
  else{
    cout << "Couldn't find your person: " << choice << endl;
  }

  return 0;
}
