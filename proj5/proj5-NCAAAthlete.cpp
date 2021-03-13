//
//  NCAAAthlete.cpp
//
//
//  Created by Aars Matthew on 2/12/18.
//

#include "proj5-NCAAAthlete.hpp"
#include <sstream>

void NCAAAthlete::setID(int id){
    this->athleteID = id;
}

void NCAAAthlete::setName(string n){
    this->athleteName = n;
}

void NCAAAthlete::setSchool(string s){
    this->schoolChoice = s;
}

void NCAAAthlete::setLOI(string loi){
    athleteLOI = loi == "yes";
}

int NCAAAthlete::getID(){
    return this->athleteID;
}

string NCAAAthlete::getName(){
    return this->athleteName;
}

string NCAAAthlete::getSchool(){
    return this->schoolChoice;
}

bool NCAAAthlete::getLOI(){
    return this->athleteLOI;
}

string NCAAAthlete::toString(){
    ostringstream out;

    out << "ID: " << this->athleteID << endl;
    out << "Name: " << this->athleteName << endl;

    if( this->athleteLOI ){
        out << "School: " << this->schoolChoice << endl;
    } else {
        out << "Available" << endl;
    }

    return out.str();
}
