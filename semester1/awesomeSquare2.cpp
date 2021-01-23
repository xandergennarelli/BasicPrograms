/*
* Author: Xander Gennarelli
* Assignment Title: Awesome Square
* Assignment Description:
*           A program that will calculate if a square is awesome and/or magic
*                 or neither.
* Due Date: 10/2/2020
* Date Created: 10/2/2020
* Date Last Modified: 10/2/2020
*/
/*
* Data Abstraction:
*           Creates numTests to hold the number of squares that will be
*                 checked.
*           Creates root to hold the size of a given square.
*           Creates val, sum, and goal to hold the current int being read, the
*                 sum of a squares row, and the expected sum.
*           Created aweOut to hold output for whether each square is
*                 is awesome.
*           Creates awesome to hold whether or not a square is awesome.
* Input:
*           The number of squares to be tested is input.
*           The size of the next square is input.
* Process:
*           The sums of each row is calculated and checked for if they match
*                 the expected sum.
*           The result of the awesome tests are recorded to a string stream.
* Output:
*           The stream of awesome test results is output.
* Assumptions:
*           It is assumed that the user will correctly input.
*/

#include <sstream>
#include <iostream>
using namespace std;

int main() {

  int numTests, root, val, sum, goal;
  stringstream aweOut;
  bool awesome;
  cin >> numTests;

  for(int test = 1; test <= numTests; test++){
    cin >> root;

    for(int i = 1; i <= root; i++){
      sum = 0;
      for(int j = 1; j <= root; j++){
        cin >> val;
        sum += val;
      }
      if(i == 1){
        goal = sum;
        awesome = true;
      }
      if(sum != goal){
        awesome = false;
      }
    }
    if(!awesome){aweOut << "Not ";}
    aweOut << "Awesome" << endl;
  }

  cout << aweOut.str();

  return 0;
}
