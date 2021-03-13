/**
 * file: NCAAAthlete.hpp
 * author: Prof. Aars
 * course: CSI 1440
 * assignment: project 6
 * due date: 2/26/2018
 *
 * date modified: 2/18/2020
 *      - changed to Coach Aranda
 * date modified: 2/14/2018
 *      - file created
 *
 * Defines the NCAAAthlete class.
 */

#ifndef NCAAATHLETE_H
#define NCAAATHLETE_H

#include <string>

using namespace std;

class NCAAAthlete {
protected:
    int athleteID;   // Unique identifier for each NCAAAthlete
    string athleteName; // NCAAAthelete's name
    // NCAAAthlete's top choice if athleteLOI is false or actual school if true
    string schoolChoice;
    bool athleteLOI;  // Stores true if letter of intent is signed false otherwise

public:
    /**
     * setID
     *
     * setId stores the passed parameter in the athleteID data member
     *
     * Parameters:
     *      id:  the number to store in the athleteID data member
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setID(int id);

    /**
     * setName
     *
     * setName stores the passed parameter in the athleteName data member
     *
     * Parameters:
     *      name: the string to store in the athleteName data member
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setName(string name);

    /**
     * setSchool
     *
     * setSchool stores the passed parameter in the schoolChoice data member
     *
     * Parameters:
     *      school: the string to store in the schoolChoice data member
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setSchool(string school);

    /**
     * setLOI
     *
     * setLOI convert the passed parameter and stores the converstion in the athleteLOI
     *   data member
     *
     * Parameters:
     *      name: the string to convert and store in the athleteLOI data member
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setLOI(string loi);

    /**
     * getID
     *
     * getId returns a copy of the athleteID data member
     *
     * Parameters:  none
     *
     * Output:
     *      return: a copy of the athleteID data member
     *      reference parameters: none
     *      stream: none
     */
    int getID();

    /**
     * getName
     *
     * getName returns a copy of the athleteName data member
     *
     * Parameters: none
     *
     * Output:
     *      return: a copy of the athleteName data member
     *      reference parameters: none
     *      stream: none
     */
    string getName();

    /**
     * getSchool
     *
     * getSchool returns a copy of the schoolChoice data member
     *
     * Parameters: none
     *
     * Output:
     *      return: a copy of the schoolChoice data member
     *      reference parameters: none
     *      stream: none
     */
    string getSchool();

    /**
     * getLOI
     *
     * getLOI returns a copy of the athleteLOI data member
     *
     * Parameters: none
     *
     * Output:
     *      return: a copy of the athleteLOI data member
     *      reference parameters: none
     *      stream: none
     */
    bool getLOI();

    /**
     * toString
     *
     * converts an instance of a NCAAAthlete into a string representtion
     *
     * Parameters: none
     *
     * Output:
     *      return: a string representation of the object
     *      reference parameters: none
     *      stream: none
     */
    string toString();
};

#endif
