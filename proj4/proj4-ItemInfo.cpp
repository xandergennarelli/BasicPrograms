/**
-  file: proj4-ItemInfo.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 4
-  due date: 03/03/2021
-
-  Date Modified: 03/03/2021
-    - File Created
*/

#include "proj4-ItemInfo.hpp"
#include <cmath>

using namespace std;

/*
* stuCstrToInt
*
* This function converts a cstring representation of a int into a int value
*
* Parameters:
*      num: the cstring holding a ascii representation of a int
*
* Output:
*      return: a int value that reflects the ascii representation found in num
*      reference parameters: none
*      stream: none
*/
int stuCstrToInt(const char *num);

/*
* stuIntToCstr
*
* This function converts a double value into a cstring representation of a int
*
* Parameters:
*      cstr: the char array holding enough space to store a ascii representation
*            of num
*      num: the int value that is converted into an ascii representation
*
* Output:
*      return: none
*      reference parameters: str should hold the ascii representatiton of num
*      stream: none
*/
void stuIntToCstr(char *cstr, int num);

/**
 * printCStringQuote
 *
 * This function writes a cstring to the passed ostream, but with "quotes"!!!
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
ostream& printCStringQuote(ostream &out, const char *src);



void ItemInfo::setItemId(const char *num){
  this->itemId = stuCstrToInt(num);
}

void ItemInfo::setDescription(const char *cstr){
  stuCstrCpy(this->description, cstr);
}

void ItemInfo::setManCost(const char *num){
  this->manCost = stuCstrToDbl(num);
}

void ItemInfo::setSellPrice(const char *num){
  this->sellPrice = stuCstrToDbl(num);
}

int ItemInfo::getItemId(){
  return this->itemId;
}

const char* ItemInfo::getDescription(){
  return this->description;
}

double ItemInfo::getManCost(){
  return this->manCost;
}

double ItemInfo::getSellPrice(){
  return this->sellPrice;
}

void ItemInfo::toAmazonJSON(ostream &out){
  char *cstr;
  printCString(out, "\t\t\t\t\"itemId\": ");
  cstr = new char[static_cast<int>(log10(this->itemId)) + 2]; //number of digits
  stuIntToCstr(cstr, this->itemId);                        //in itemId plus room
  printCString(out, cstr);                                 //for '\0'
  delete [] cstr;

  printCStringQuote(out, ",\n\t\t\t\t\"description\": \"");
  printCStringQuote(out, this->description);

  printCStringQuote(out, "\",\n\t\t\t\t\"manCost\": ");
  cstr = new char[static_cast<int>(log10(this->manCost)) + 5];//extra space for
  stuDblToCstr(cstr, this->manCost);                          // '.##'
  printCString(out, cstr);
  delete [] cstr;

  printCStringQuote(out, ",\n\t\t\t\t\"sellPrice\": ");
  cstr = new char[static_cast<int>(log10(this->sellPrice)) + 5];
  stuDblToCstr(cstr, this->sellPrice);
  printCString(out, cstr);
  out.put('\n');
  delete [] cstr;
}

void ItemInfo::displayItemInfo(ostream &out){
  char *cstr;

  printCString(out, "itemId: ");
  cstr = new char[static_cast<int>(log10(this->itemId)) + 2]; //number of digits
  stuIntToCstr(cstr, this->itemId);                        //in itemId plus room
  printCString(out, cstr);                                 //for '\0'
  delete [] cstr;

  printCString(out, "\ndescription: ");
  printCString(out, this->description);


  //FIXME: !!! log10 of a num less than 1 is bad!!
  printCString(out, "\nmanCost: ");
  cstr = new char[static_cast<int>(log10(this->manCost)) + 5];//extra space for
  stuDblToCstr(cstr, this->manCost);                          // '.##'
  printCString(out, cstr);
  delete [] cstr;

  printCString(out, "\nsellPrice: ");
  cstr = new char[static_cast<int>(log10(this->sellPrice)) + 5];
  stuDblToCstr(cstr, this->sellPrice);
  printCString(out, cstr);
  delete [] cstr;

  printCString(out, "\ncalculatedProfit: ");
  cstr = new char[static_cast<int>(log10(this->calcProfit())) + 5];
  stuDblToCstr(cstr, this->calcProfit());
  printCString(out, cstr);
  out.put('\n');
}

double ItemInfo::calcProfit(){
  return (this->sellPrice - this->manCost);
}



double stuCstrToDbl(const char *num){
  double val = 0.0, decPlace = 10.0;
  int i = 0;
  while (*(num + i) != '\0' && *(num + i) != '.'){//places whole digits
    val *= 10.0;
    val += static_cast<double>(*(num + i) - '0');
    i++;
  }
  if (*(num + i) == '.'){
    i++;
    while (*(num + i) != '\0'){ //places post-decimal digits
      val += static_cast<double>(*(num + i) - '0') / decPlace;
      decPlace *= 10.0;
      i++;
    }
  }
  return val;
}

int stuCstrToInt(const char *num){
  int val = 0, i = 0;
  cout << num << " ";
  while (*(num + i) != '\0'){
    val *= 10;
    val += static_cast<int>(*(num + i) - '0');
    i++;
  }
  cout << " " << val << endl;
  return val;
}

void stuDblToCstr(char *cstr, double num){
  int topDigit;
  if (num < 1.0) topDigit = 0;
  else topDigit = static_cast<int>(log10(static_cast<int>(num)));
  *(cstr + topDigit + 1) = '.';
  num *= 100;
  for (int i = 2; i > 0; i++){ //places 2 post-decimal digits
    *(cstr + topDigit + 1 + i) = (static_cast<int>(num) % 10 + '0');
    num /= 10;
  }
  *(cstr + topDigit + 4) = '\0';
  for (int i = topDigit; i >= 0; i--){ //places whole digits
    *(cstr + i) = (static_cast<int>(num) % 10 + '0');
    num /= 10;
  }
  //cout << "!!  " << cstr << endl;
}

void stuIntToCstr(char *cstr, int num){
  int topDigit = static_cast<int>(log10(num));
  *(cstr + topDigit + 1) = '\0';
  for (int i = topDigit; i >= 0; i--){
    *(cstr + i) = num % 10;
    num /= 10;
  }
}

void stuCstrCpy(char *dest, const char *src){
  int i = 0;
  while (*(src + i) != '\0'){
    dest[i] = src[i];
    i++;
  }
}

int stuCstrLen(const char *src){
  int len = 0;
  while (*(src + len) != '\0') len++;
  return len;
}

ostream& printCString(ostream &out, const char *src){
  int i = 0;
  while (*(src + i) != '\0'){
    out.put(*(src + i));
    i++;
  }
  return out;
}

ostream& printCStringQuote(ostream &out, const char *src){
  out.put('\"');
  printCString(out, src);
  out.put('\"');
  return out;
}
