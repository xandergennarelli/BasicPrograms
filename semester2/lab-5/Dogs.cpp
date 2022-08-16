/*
 * file: Driver7.cpp
 * author: Xander Gennarelli
 * course: CSI 1440
 * assignment: lab 5
 * due date: 3/10/2021
 *
 * date modified:  3/10/2021
 *    - file created
 *    - added WalkTheDog() and BegForFood() functions and testing cases
 *    - added test cases for HuckleberryHound, Poodle, ScoobyDoo, and
 *          GermanSheperd
 *    - made test cases dynamically created
 *
 * Provides a driver to test Dog classes.
 */
#include "Dogs.h"

/**
 * WalkTheDog
 *
 * This function calls the functions Pant(), Bark(), and Pant() (again) for the
 *    passed Dog object.
 *
 * Parameters: none
 *
 * Output:
 *      return: none
 *      reference parameters: reference to aDog
 *      stream: none
 */
void WalkTheDog( Dog &aDog );

/**
 * BegForFood
 *
 * This function calls the functions Wimper() and Bark() for the passed Dog
 *    object.
 *
 * Parameters: none
 *
 * Output:
 *      return: none
 *      reference parameters: reference to aDog
 *      stream: none
 */
void BegForFood( Dog &aDog );

int main() {
  // generate array of Dog pointers
  Dog *doggies[] = { new Dog("Fido"), new BostonTerrier("Dixie"), new Heinz57("Bones"),
            new HuckleberryHound("Huck"), new Poodle("Frenchy"),
            new ScoobyDoo("Scooby"), new GermanSheperd("SgtShultz") };

  for( int i = 0; i < 7; i++ ) { // tests getName() and WalkTheDog()
    cout << "Walking " << doggies[i]->getName() << "..." << endl;
    WalkTheDog( *doggies[i] );

    cout << endl << doggies[i]->getName() << " is begging again..." << endl;

    // tests BegForFood()
    BegForFood( *doggies[i] );
    cout << endl;
  }

  return 0;
}

void WalkTheDog( Dog &aDog ) {
  aDog.Pant();
  aDog.Bark();
  aDog.Pant();
}

void BegForFood( Dog &aDog ) {
  aDog.Wimper();
  aDog.Bark();
}
