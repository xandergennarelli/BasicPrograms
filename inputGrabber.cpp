/*
* Author: Xander Gennarelli
* Assignment Title: Awesome Square
* Assignment Description:
*           A program that will calculate if a square is awesome and/or magic
*                 or neither.
* Due Date: 10/2/2020
* Date Created: 10/1/2020
* Date Last Modified: 10/2/2020
*/
/*
* Data Abstraction:
*           Creates numTests to hold the number of squares that will be
*                 checked.
*           Creates root to hold the size of a given square.
*           Creates sum, dsum, and goal to hold the sum of a squares row or
*                 column, the sum of a rows diagonal, and the expected sum.
*           Creates square to hold a 2d vector representing the square.
*           Creates numList to hold the expected values within a square.
*           Created aweOut and magOut to hold output for whether each square is
*                 is awesome or magic respectively.
*           Creates magic and awesome to hold whether or not a square has been
*                 found to be not magic or not awesome.
* Input:
*           The number of squares to be tested is input.
*           The size of the next square is input.
*           The square is read and recorded as a 2d vector.
* Process:
*           Per-square values are reset.
*           If the root is 0 the square is not awesome or magic.
*           2d square vector is reset and resized to fit root.
*           The sums of each row is calculated and checked for if they match
*                 the expected sum.
*           The list of expected values is generated.
*           The column sums, and diagonal sums are checked against the
*                 expected sum, and the square is checked for repeating
*                 values.
*           The result of the awesome and magic tests are recorded to string
*                 streams.
* Output:
*           The stream of awesome test results is output.
*           Start extra credit is printed.
*           The stream of magic test results is output.
*           End extra credit is printed.
* Assumptions:
*           It is assumed that the user will correctly input.
*
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  string out;
  while(getline(cin, out)){
    cout << out << endl;
    out = "";
  }

  return 0;
}
