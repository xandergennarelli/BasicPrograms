#include <iostream>
#include <string>

enum Cond {excellent, veryGood, good, fair};
enum Color {red, blue, green, silver, white, black};

struct Car {
  Cond condition;
  string make;
  string model;
  float askPrice;
  Color ext;
  Color interior;
};

istream & getACar(istream &, Car *);
void sortByPrice(Car **, int);
Car * findCar(Car **, int, string); // find by make
void displayCar(ostream &, const Car *);
