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
*           While all squares have not been tested:
*             Per-square values are reset.
*             If the root is 0 the square is not awesome or magic.
*             2d square vector is reset and resized to fit root.
*             The sums of each row is calculated and checked for if they match
*                   the expected sum.
*             The list of expected values is generated.
*             The column sums, and diagonal sums are checked against the
*                   expected sum, and the square is checked for repeating
*                   values.
*             The result of the awesome and magic tests are recorded to string
*                   streams.
* Output:
*           The stream of awesome test results is output.
*           Start extra credit is printed.
*           The stream of magic test results is output.
*           End extra credit is printed.
* Assumptions:
*           It is assumed that the user will correctly input.
*
*/

#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  //DATA ABSTRACTION
  int numTests, root, sum, dsum, goal;
  vector<vector<int>> square;
  vector<int> numList;
  stringstream aweOut, magOut;
  bool magic, awesome;

  //INPUT/PROCESS
  cin >> numTests;

  while(numTests > 0){
    awesome = true; //awesome until proven not awesome.
    magic = true;
    dsum = 0;
    goal = 0;

    cin >> root;
    if(root == 0){
      awesome = false;
      magic = false;
    }

    square.clear();
    square.resize(root);
    for(int i = 0; i < root; i++){//reads rows and checks row sums (awesome)
      square[i].resize(root);
      sum = 0;
      for(int j = 0; j < root; j++){
        cin >> square[i][j];
        sum += square[i][j];
      }
      if(i == 0){
        goal = sum;
      }
      if(goal != sum){
        awesome = false;
        magic = false;
      }
    } //now have 2d vector of the square

    numList.clear();
    numList.resize(root * root);
    for(unsigned int i = 0; i < numList.size(); i++){//creates a list of
      numList[i] = i + 1;                            //expected values.
    }

    for(int i = 0; i < root; i++){//checks column sums and calcs diagonal sum
      sum = 0;                    //and checks if a number is use more than
      dsum += square[i][i];       //once. (magic)

      for(int j = 0; j < root; j++){
        sum += square[j][i];

        if(numList[square[i][j] - 1] == 0){
          magic = false;    //checks if the value at square[i][j] has been
        }                   //used already in the square.
        numList[square[i][j] - 1] = 0; //marks value at current index as used.
      }

      if(goal !=  sum){
        magic = false;
      }
    }
    if(dsum != goal){
      magic = false;
    }

    if(awesome){aweOut << "Awesome" << endl;}
    else{aweOut << "Not Awesome" << endl;}
    if(magic){magOut << "Magic" << endl;}
    else{magOut << "Not Magic" << endl;}

    numTests--;
  }

  //OUTPUT

  cout << aweOut.str() << endl;

  //EXTRA CREDIT
  cout << "\n*** Start Extra Credit ***\n" << endl;

  cout << magOut.str() << endl;

  cout << "\n*** End Extra Credit ***" << endl;

  return 0;
}
