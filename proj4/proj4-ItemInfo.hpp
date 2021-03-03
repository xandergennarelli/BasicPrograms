/**
 * file: proj4-ItemInfo.hpp
 * author: Prof. Aars
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/7/2018
 *
 * date modified:  1/28/2018
 *    - file created
 *
 * This class provides a container for products contained in a produce service dump.
 */

#ifndef ITEMINFO_H
#define ITEMINFO_H

#include <iostream>
#include <iomanip>

using namespace std;

class ItemInfo {
private:
    int itemId;
    char description[40];
    double manCost;
    double sellPrice;
public:
    ItemInfo() {
        itemId = 0;
        *description = '\0';
        manCost = 0.0;
        sellPrice = 0.0;
    }

    /**
     * setItemId
     *
     * This function stores an integer representation of a cstring into the itemId data
     * member of the ItemInfo class.
     *
     * Parameters:
     *      num:  a cstring representation of an integer value
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setItemId(const char *num);

    /**
     * setDescription
     *
     * This function stores a copy of the passed cstring into the description data member
     * of the ItemInfo class
     *
     * Parameters:
     *      cstr:  a cstring containing the description of the product
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setDescription(const char *cstr);

    /**
     * setManCost
     *
     * This function stores an double representation of a cstring into the manCost data
     * member of the ItemInfo class.
     *
     * Parameters:
     *      num:  a cstring representation of an double value
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setManCost(const char *num);

    /**
     * setSellPrice
     *
     * This function stores an double representation of a cstring into the sellPrice data
     * member of the ItemInfo class.
     *
     * Parameters:
     *      num:  a cstring representation of an double value
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setSellPrice(const char *num);

    /**
     * getItemId
     *
     * This function returns a copy of the value stored in the itemId data memeber of the
     * ItemInfo class.
     *
     * Parameters: none
     *
     * Output:
     *      return: a copy of itemId
     *      reference parameters: none
     *      stream: none
     */
    int getItemId();

    /**
     * getDescription
     *
     * This function returns a const reference to the description data member of the
     * ItemInfo class.
     *
     * Parameters: none
     *
     * Output:
     *      return: a const reference to description
     *      reference parameters: none
     *      stream: none
     */
    const char *getDescription();

    /**
     * getManCost
     *
     * This function returns a copy of the value stored in the manCost data memeber of the
     * ItemInfo class.
     *
     * Parameters: none
     *
     * Output:
     *      return: a copy of manCost
     *      reference parameters: none
     *      stream: none
     */
    double getManCost();

    /**
     * getSellPrice
     *
     * This function returns a copy of the value stored in the sellPrice data memeber of
     * the ItemInfo class.
     *
     * Parameters: none
     *
     * Output:
     *      return: a copy of sellPrice
     *      reference parameters: none
     *      stream: none
     */
    double getSellPrice();

    /**
     * toAmazonJSON
     *
     * This function outputs the data members of the ItemInfo class in a JSON formate
     * specified by Amazon.
     *
     * Parameters:
     *      out: the ouput stream for the JSON format
     *
     * Output:
     *      return: none
     *      reference parameters: the updated ostream
     *      stream: none
     */
    void toAmazonJSON(ostream &out);

    /**
     * displayItemInfo
     *
     * This function outputs the data members of the ItemInfo class in a formate specified
     * by Prof. Aars.
     *
     * Parameters:
     *      out: the ouput stream for the specified format
     *
     * Output:
     *      return: none
     *      reference parameters: the updated ostream
     *      stream: none
     */
    void displayItemInfo(ostream &out);


    /**
     * calcProfit
     *
     * This function computes the difference beteween an ItemInfo's manCost and sellPrice
     * data memebers.
     *
     * Parameters: none
     *
     * Output:
     *      return: the difference between manCost and sellPrice
     *      reference parameters: none
     *      stream: none
     */
    double calcProfit();
};

/**
 * stuCstrToDbl
 *
 * This function converts a cstring representation of a double into a double value
 *
 * Parameters:
 *      num: the cstring holding a ascii representation of a double
 *
 * Output:
 *      return: a double value that reflects the ascii representation found in num
 *      reference parameters: none
 *      stream: none
 */
double stuCstrToDbl(const char *num);

/**
 * stuDblToCstr
 *
 * This function converts a double value into a cstring representation of a double
 *
 * Parameters:
 *      cstr: the char array holding enough space to store a ascii representation of num
 *      num: the double value that is converted into an ascii representation
 *
 * Output:
 *      return: none
 *      reference parameters: str should hold the ascii representatiton of num
 *      stream: none
 */
void stuDblToCstr(char *cstr, double num);

/**
 * stuCstrCpy
 *
 * This function copies the cstring src into dest
 *
 * Parameters:
 *      dest: the char array that hold a copy of the contents of src.  dest must have
 *            enough space to store the copy
 *      src: the cstring to be copied
 *
 * Output:
 *      return: none
 *      reference parameters: dest should hold a copy of src
 *      stream: none
 */
void stuCstrCpy(char *dest, const char *src);

/**
 * stuCstrLen
 *
 * This function caculates the length of a cstring
 *
 * Parameters:
 *      src: the cstring for which the length is calculated
 *
 * Output:
 *      return: an integer storing the length of the cstring
 *      reference parameters: none
 *      stream: none
 */
int stuCstrLen(const char *src);

/**
 * printCString
 *
 * This function writes a cstring to the passed ostream
 *
 * Parameters:
 *      out: the ostream for the cstring to be displayed
 *      src: the cstring to be displayed
 *
 * Output:
 *      ostream &: a reference to the passed ostream
 *      reference parameters: out
 *      stream: none
 */
ostream& printCString(ostream &out, const char *src);

#endif
