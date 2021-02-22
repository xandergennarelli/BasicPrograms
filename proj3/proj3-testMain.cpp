/**
-  file: proj3-testmain.cpp
-  author: Xander Gennarelli
-  course: CSI 1440
-  assignment: Project 3
-  due date: 02/22/2021
-
-  Date Modified: 02/19/2021
-    - File Created
*/
#include "proj3-MyString.h"
#include <cstring>
#include <sstream>
using namespace std;

void fillArray(char *ptrs, string str);

int main(){
  stringstream ss;

  char *str_a = new char[5];
  strcpy(str_a, "hello");
  char *str_b = new char[13];
  strcpy(str_b, "hello, world!");
  char *str_c = new char[21];
  strcpy(str_c, "pizza!\nparty!\nhooray!");
  char *str_d = new char[6];
  strcpy(str_d, "whoa~~");

  MyString a(str_a);
  MyString b(str_b);
  MyString c(str_c);
  MyString d(str_d);

  MyString a_cpy(a);
  MyString b_cpy(b);
  MyString c_cpy(c);

  MyString def;

  delete [] str_a;
  delete [] str_b;
  delete [] str_c;
  delete [] str_d;

  cout << "### Printing string-initialized MyStrings ###" << endl;
  cout << a << endl << endl;
  cout << b << endl << endl;
  cout << c << endl << endl << endl;

  cout << "### Printing default MyString ###" << endl;
  cout << def << endl << endl << endl;

  cout << "### Printing copy-initialized MyStrings ###" << endl;
  cout << a_cpy << endl << endl;
  cout << b_cpy << endl << endl;
  cout << c_cpy << endl << endl << endl;

  cout << "### Testing == operator ###" << endl;
  cout << "MyString a and a :: " << (a == a) << endl;
  cout << "MyString a and copy of a :: " << (a == a_cpy) << endl;
  cout << "MyString b and a :: " << (b == a) << endl;
  cout << "MyString b and c :: " << (b == c) << endl;
  b = a;
  cout << "# after assigning b to a #" << endl;
  cout << "MyString b and a :: " << (b == a) << endl << endl;

  cout << "### Testing = operator ###" << endl;
  cout << "# after assigning b to a #" << endl;
  cout << "a ::" << endl;
  cout << a << endl << endl;
  cout << "b ::" << endl;
  cout << b << endl << endl;
  cout << "c ::" << endl;
  cout << c << endl << endl;
  cout << "# after assigning a to c #" << endl;
  a = c;
  cout << "a ::" << endl;
  cout << a << endl << endl;
  cout << "b ::" << endl;
  cout << b << endl << endl;
  cout << "c ::" << endl;
  cout << c << endl << endl << endl;

  cout << "### Testing [ ] operator ###" << endl;
  cout << "\"" << b << "\" pos: 0 -> " << b[0] << endl;
  cout << "\"" << b << "\" pos: 4 -> " << b[4] << endl;
  cout << "\"" << b_cpy << "\" pos: 12 -> " << b_cpy[12] << endl << endl;

  cout << "### Testing + operator ###" << endl;
  MyString db = d + b;
  MyString b_cpya_cpy = b_cpy + a_cpy;
  MyString b_cpyb_cpy = b_cpy + b_cpy;
  cout << "\"" << d << "\" + \"" << b << "\" -> " << db << endl << endl;
  cout << "\"" << b_cpy << "\" + \"" << a_cpy << "\" -> " << b_cpya_cpy << endl
       << endl;
  cout << "\"" << b_cpy << "\" + \"" << b_cpy << "\" -> " << b_cpyb_cpy << endl
       << endl << endl;

  cout << "### Testing += operator ###" << endl;
  cout << "\"" << d << "\" += \"" << b << "\" -> ";
  d += b;
  cout << d << endl << endl;
  cout << "\"" << b_cpy << "\" += \"" << a_cpy << "\" -> ";
  b_cpy += a_cpy;
  cout << b_cpy << endl << endl;
  cout << "\"" << b_cpy << "\" += \"" << b_cpy << "\" -> ";
  b_cpy += b_cpy;
  cout << b_cpy << endl << endl << endl;

  cout << "### Testing length() ###" << endl;
  cout << "length of \"" << a << "\" -> " << a.length() << endl;
  cout << "length of \"" << d << "\" -> " << d.length() << endl;
  cout << "length of \"" << b_cpy << "\" -> " << b_cpy.length() << endl;
  cout << "length of \"" << def << "\" -> " << def.length() << endl;
  cout << "length of \"" << b_cpya_cpy << "\" -> " << b_cpya_cpy.length()
       << endl << endl;

  cout << "### Testing getline() ###" << endl;
  cout << "in the stringstream being read from ::\n###\n"
       << "hello\nhel lo world\n\npizza!" << "\n###" << endl;
  ss.str("hello\nhel lo world\n\npizza!");
  d.getline(ss);
  cout << "getline() 1 with default delimit char -> " << d << endl;
  d.getline(ss, 'r');
  cout << "getline() 2 with \'r\' delimit char -> " << d << endl;
  d.getline(ss);
  cout << "getline() 3 with default delimit char -> " << d << endl;
  d.getline(ss);
  cout << "getline() 4 with default delimit char -> " << d << endl;
  d.getline(ss);
  cout << "getline() 5 with default delimit char -> " << d << endl;
  d.getline(ss);
  cout << "getline() 6 with default delimit char -> " << d << endl << endl;

  cout << "### Testing << operator ###" << endl;
  cout << "I mean... that ^^^ was all testing for \"<<\"..." << endl;

  return 0;
}
