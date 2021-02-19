#include <iostream>

using namespace std;

int profStrLen( char * );
int stuStrLen( char * );
char *profStrCpy( char *, char * );
char *stuStrCpy( char *, char * );
char *profStrCat( char *, char * );
char *stuStrCat( char *, char * );
int stuStrCmp( char *, char * );
int mystery( char * );

int main() {
  char *a, *b, *c, *d, *e;
  cout << "### testing profStrLen() :: " << endl;

  cout << "\"hello\" -> " << profStrLen("hello") << endl;

  cout << "\"\" -> " << profStrLen("") << endl;
  cout << "\"abcdefghijklmnopqrstuvwxyz\" -> "
       << profStrLen("abcdefghijklmnopqrstuvwxyz") << endl;

  cout << "\"100\" -> " << profStrLen("100") << endl;

  cout << "\"\\n\" -> " << profStrLen("\n") << endl;
  cout << endl;

  cout << "### testing stuStrLen() :: " << endl;

  cout << "\"hello\" -> " << stuStrLen("hello") << endl;

  cout << "\"\" -> " << stuStrLen("") << endl;

  cout << "\"abcdefghijklmnopqrstuvwxyz\" -> "
       << stuStrLen("abcdefghijklmnopqrstuvwxyz") << endl;

  cout << "\"100\" -> " << stuStrLen("100") << endl;

  cout << "\"\\n\" -> " << stuStrLen("\n") << endl;
  cout << endl;


  a = new char[5];
  b = new char[0];
  c = new char[26];
  d = new char[3];
  e = new char[1];
  cout << "### testing profStrCpy() :: " << endl;

  profStrCpy(a, "hello");
  cout << "\"hello\" -> " << a << endl;

  profStrCpy(b, "");
  cout << "\"\" -> " << b << endl;

  profStrCpy(c, "abcdefghijklmnopqrstuvwxyz");
  cout << "\"abcdefghijklmnopqrstuvwxyz\" -> " << c << endl;

  profStrCpy(d, "100");
  cout << "\"100\" -> " << d << endl;

  profStrCpy(e, "\n");
  cout << "\"\\n\" -> " << e << endl;
  cout << endl;
  delete a; delete b; delete c; delete d; delete e;


  a = new char[5];
  b = new char[0];
  c = new char[26];
  d = new char[3];
  e = new char[1];
  cout << "### testing stuStrCpy() :: " << endl;

  stuStrCpy(a, "hello");
  cout << "\"hello\" -> " << a << endl;

  stuStrCpy(b, "");
  cout << "\"\" -> " << b << endl;

  stuStrCpy(c, "abcdefghijklmnopqrstuvwxyz");
  cout << "\"abcdefghijklmnopqrstuvwxyz\" -> " << c << endl;

  stuStrCpy(d, "100");
  cout << "\"100\" -> " << d << endl;

  stuStrCpy(e, "\n");
  cout << "\"\\n\" -> " << e << endl;
  cout << endl;
  delete a; delete b; delete c; delete d; delete e;


  cout << "### testing profStrCat() :: " << endl;

  a = new char[5];
  profStrCpy(a, "hello");
  profStrCat(a, ", world!");
  cout << "\"hello\" + \", world!\" -> " << a << endl;
  delete a;

  b = new char[0];
  profStrCpy(b, "");
  profStrCat(b, "--");
  cout << "\"\" + \"--\" -> " << b << endl;
  delete b;

  c = new char[13];
  profStrCpy(c, "abcdefghijklm");
  profStrCat(c, "nopqrstuvwxyz");
  cout << "\"abcdefghijklm\" + \"nopqrstuvwxyz\" -> " << c << endl;
  delete c;

  d = new char[3];
  profStrCpy(d, "100");
  profStrCat(d, " thousand");
  cout << "\"100\" + \" thousand\" -> " << d << endl;
  delete d;

  e = new char[15];
  profStrCpy(e, "word word word ");
  profStrCat(e, "word word word ");
  cout << "\"word word word \" + \"word word word \" -> " << e << endl;
  cout << endl;
  delete e;
  cout << endl;


  cout << "### testing stuStrCat() :: " << endl;

  a = new char[5];
  stuStrCpy(a, "hello");
  stuStrCat(a, ", world!");
  cout << "\"hello\" + \", world!\" -> " << a << endl;
  delete a;

  b = new char[0];
  stuStrCpy(b, "");
  stuStrCat(b, "--");
  cout << "\"\" + \"--\" -> " << b << endl;
  delete b;

  c = new char[13];
  stuStrCpy(c, "abcdefghijklm");
  stuStrCat(c, "nopqrstuvwxyz");
  cout << "\"abcdefghijklm\" + \"nopqrstuvwxyz\" -> " << c << endl;
  delete c;

  d = new char[3];
  stuStrCpy(d, "100");
  stuStrCat(d, " thousand");
  cout << "\"100\" + \" thousand\" -> " << d << endl;
  delete d;

  e = new char[15];
  stuStrCpy(e, "word word word ");
  stuStrCat(e, "word word word ");
  cout << "\"word word word \" + \"word word word \" -> " << e << endl;
  cout << endl;
  delete e;
  cout << endl;


  cout << "### testing stuStrCmp() :: " << endl;
  cout << "\"hello\" - \"hello\" -> " << stuStrCmp("hello", "hello") << endl;
  cout << "\"\" - \" \" -> " << stuStrCmp("", " ") << endl;
  cout << "\"abcdefghijklmnopqrstuvwxyz\" - \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\" -> "
       << stuStrCmp("abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
       << endl;
  cout << "\"100\" - \"1000\" -> " << stuStrCmp("100", "1000") << endl;
  cout << "\"pizza\" - \"apple\" -> " << stuStrCmp("pizza", "apple") << endl;
  cout << endl;
  
  return 0;
}

int profStrLen( char *str ) {
  char *endOfStr = str;
  while( *endOfStr != '\0' ) {
     endOfStr++;
  }
  return (int)(endOfStr - str);
}

int stuStrLen( char *str ) {
   int size = 0;
   while (str[size] != '\0'){
      size++;
   }
   return size;
}

char *profStrCpy( char *str1, char *str2 ) {
  char *dest = str1;
  while( *str2 != '\0' ) {
    *str1 = *str2;
    str1++;
    str2++;
  }
  *str1 = '\0';
  return dest;
}

char *stuStrCpy( char *str1, char *str2 ) {
   char *dest = str1;
   int i = 0;
   while (str2[i] != '\0'){
     str1[i] = str2[i];
     i++;
   }
   str1[i] = '\0';
   return dest;
}

char *profStrCat( char *str1, char *str2 ) {
  char *dest = str1;
  while( *str1 != '\0' ) {
    str1++;
  }
  while( *str2 != '\0' ) {
    *str1 = *str2;
    str1++;
    str2++;
  }
  *str1 = '\0';
  return dest;
}

char *stuStrCat( char *str1, char *str2 ){
  char *dest = str1;
  int i = 0, j = 0;
  while (str1[i] != '\0'){
    i++;
  }
  while (str2[j] != '\0'){
    str1[i] = str2[j];
    i++;
    j++;
  }
  str1[j] = '\0';
  return dest;
}

int stuStrCmp( char *str1, char *str2 ){
  int diff = 0, i = 0;
  while (str1[i] != '\0' && str2[i] != '\0' && diff == 0){
    diff = (int) (str1[i] - str2[i]);
    i++;
  }
  if (diff == 0){ //for the case where one string is a substring of the other.
    diff = (int) (str1[i] - str2[i]);
  }
  return diff;
}

int mystery( char *str ) { // probably should be named stoi().
  char *str2 = str; // str2 pointer is assigned the pointer str.
  long pos;
  int result = 0;

  while( *str2 != '\0' ) { // loop points str2 at the null character/the end of
    str2++;               //  the string.
  }
  pos = str2 - str - 1; // pos is equal to the length of the string.

  for( int count = 1; pos >= 0; pos --, count *= 10 ) { // iterates backwards
    if( str[pos] == '-') {                             //  through str.
      result *= -1;         // makes the result negative if a '-' is found.
    } else {
      result += (str[pos] - '0') * count; // converts the str characters into
    }                                    //  a decimal int. count sets the
  }                                     //   place.
  return result; // returns an int parsed from the str.
}
