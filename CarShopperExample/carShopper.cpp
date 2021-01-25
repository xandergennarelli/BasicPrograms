#include <iostream>
#include <string>
#include "carShopper.h"

using namespace std;

istream & getACar(istream &in, Car *aCar){
  in >> aCar->condition;
  in.ignore(2, '\n');
  getline(in, aCar->make);
  getline(in, aCar->model);
  in >> aCar->askPrice >> aCar->ext >> aCar->interior;

  return in;
}

void sortByPrice(Car **carLot, int size){
  
}

Car * findCar(Car **carLot, int size, string make){

}

void displayCar(ostream &out, const Car *aCar){

}
