/*
 * file: Dogs6.h
 * author: Xander Gennarelli
 * course: CSI 1440
 * assignment: lab 5
 * due date: 3/10/2021
 *
 * date modified:  3/10/2021
 *    - file created
 *    - edited BostonTerrier and Heinz57 classes to inherit from Dog
 *    - added overrided Bark() function to BostonTerrier class
 *    - added Wimper() and Pant() functions to the Dog base class
 *    - made Dog::Bark() a virtual function
 *    - added HuckleberryHound, Poodle, ScoobyDoo, and GermanSheperd classes
 */
#ifndef DOGS_H
#define DOGS_H

#include <iostream>
#include <string>

using namespace std;

class Dog {
private:
  string name;

public:
  Dog( string n ) {
    name = n;
  }

  /**
   * getName
   *
   * This function returns a copy of the string member value name.
   *
   * Parameters: none
   *
   * Output:
   *      return: a copy of name
   *      reference parameters: none
   *      stream: none
   */
  string getName() {
    return name;
  }

  /**
   * Bark
   *
   * This function prints "Bow-Wow" to the terminal.
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void virtual Bark() {
    cout << "Bow-Wow" << endl;
  }

  /**
   * Wimper
   *
   * This function prints "Rrrrrrrrr" to the terminal.
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void Wimper() {
    cout << "Rrrrrrrrr" << endl;
  }

  /**
   * Wimper
   *
   * This function prints "Ah-ha-ha-ha-ha" to the terminal.
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void Pant() {
    cout << "Ah-ha-ha-ha-ha" << endl;
  }
};

class BostonTerrier : public Dog {
public:
  BostonTerrier( string n ) : Dog( n ) { }

  /**
   * Bark
   *
   * This function prints "Arf-Arf" to the terminal. Overrides Dog::Bark().
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void Bark() {
    cout << "Arf-Arf" << endl;
  }
};

class Heinz57 : public Dog {
public:
  Heinz57( string n ) : Dog( n ) { }
};

class HuckleberryHound : public Dog {
public:
  HuckleberryHound( string n ) : Dog( n ) { }

  /**
   * Bark
   *
   * This function prints "Oh, my darlin" to the terminal. Overrides Dog::Bark().
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void Bark() {
    cout << "Oh, my darlin" << endl;
  }
};

class Poodle : public Dog {
public:
  Poodle( string n ) : Dog( n ) { }

  /**
   * Bark
   *
   * This function prints "Oui-Oui" to the terminal. Overrides Dog::Bark().
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void Bark() {
    cout << "Oui-Oui" << endl;
  }
};

class ScoobyDoo : public Dog {
public:
  ScoobyDoo( string n ) : Dog( n ) { }

  /**
   * Bark
   *
   * This function prints "Ruh-Roh" to the terminal. Overrides Dog::Bark().
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void Bark() {
    cout << "Ruh-Roh" << endl;
  }
};

class GermanSheperd : public Dog {
public:
  GermanSheperd( string n ) : Dog( n ) { }

  /**
   * Bark
   *
   * This function prints "I see nothing!" to the terminal. Overrides Dog::Bark().
   *
   * Parameters: none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void Bark() {
    cout << "I see nothing!" << endl;
  }
};

#endif
