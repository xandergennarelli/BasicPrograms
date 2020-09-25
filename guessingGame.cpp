/*
* Author: Xander Gennarelli
* Assignment Title: Guessing Game
* Assignment Description:
*
* Due Date: 9/28/2020
* Date Created: 9/25/2020
* Date Last Modified: 9/25/2020
*/
/*
* Data Abstraction:
*
* Input:
*
* Process:
*
* Output:
*
* Assumptions:
*
*/

#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
  //DATA ABSTRACTION
  int n1, n2, rand, guess, count = 0;

  //INPUT
  cout << "Please enter 2 integers: ";
  cin << n1 << n2;
  cout << n1 << " " << n2 << endl;

  if(n1 > n2){
    swap(n1, n2);
  }
}




/*

Please enter 2 integers: 1 10
I'm thinking of a number between 1 and 10.
Enter guess: 1 - Too Low
Enter guess: 2 - Too Low
Enter guess: 3 - Too Low
Enter guess: 4 - Too Low
Enter guess: 5 - Too Low
Enter guess: 6 - Too Low
Enter guess: 7 - Too Low
Enter guess: 8 - Too Low
Enter guess: 9
Correct, it took you 9 tries to guess my number.


Please enter 2 integers: -10 10
I'm thinking of a number between -10 and 10.
Enter guess: 4 - Too Low
Enter guess: 3 - Too Low
Enter guess: -3 - Too Low
Enter guess: -6 - Too Low
Enter guess: 5 - Too Low
Enter guess: -2 - Too Low
Enter guess: 1 - Too Low
Enter guess: -4 - Too Low
Enter guess: 8
Correct, it took you 9 tries to guess my number.


Please enter 2 integers: -10 -5
I'm thinking of a number between -10 and -5.
Enter guess: 4 - Too High
Enter guess: 3 - Too High
Enter guess: -3 - Too High
Enter guess: -6 - Too High
Enter guess: 5 - Too High
Enter guess: -2 - Too High
Enter guess: 1 - Too High
Enter guess: -4 - Too High
Enter guess: 8 - Too High
Enter guess: -1 - Too High
Enter guess: 7 - Too High
Enter guess: -7 - Too High
Enter guess: -9 - Too High
Enter guess: -10
Correct, it took you 14 tries to guess my number.


Please enter 2 integers: 22 -18
I'm thinking of a number between -18 and 22.
Enter guess: 22 - Too High
Enter guess: 10 - Too Low
Enter guess: 14 - Too Low
Enter guess: -11 - Too Low
Enter guess: 18
Correct, it took you 5 tries to guess my number.

*/
