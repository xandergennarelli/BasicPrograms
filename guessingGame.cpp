/*
* Author: Xander Gennarelli
* Assignment Title: Guessing Game
* Assignment Description:
*           A program that will ask a user for two integers and choose a random
*                 number between those integers. The user will then guess the
*                 generated number while the program tells the user if they are
*                 guessing too high or low. The number of guesses are then
*                 reported.
* Due Date: 9/28/2020
* Date Created: 9/25/2020
* Date Last Modified: 9/28/2020
*/
/*
* Data Abstraction:
*           Creates n1 and n2 for user input.
*           Creates answer to hold the random number generated.
*           Creates guess to hold user guesses.
*           Creates count to record the number of guesses.
* Input:
*           User inputs two integers.
*           User inputs a guess number until they are correct.
* Process:
*           The user input re-ordered to so n1 is less than n2 if necessary.
*           rand() is seeded with time and then used to generate a random value
*                within the range set by the user.
*           The users guesses are counted.
* Output:
*           The user is asked for two integers.
*           The input is echo printed.
*           The user is asked for a guess.
*           The guess is echo printed.
*           If the guess is greater than the answer, Too High is printed.
*           If the guess is less than the answer, Too Low is printed.
*           Once the user guesses correctly, a message is printed with the
*                 number of guesses.
* Assumptions:
*           It is assumed that the user will input correctly.
*           It is assumed that the user will eventually guess correctly.
*           It is assumed that input needs to be echo printed.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
  //DATA ABSTRACTION
  int n1, n2, answer, guess, count = 0;

  //INPUT / PROCESS
  cout << "Please enter 2 integers: ";
  cin >> n1 >> n2;
  cout << n1 << " " << n2 << endl; //Echo Print

  if(n1 > n2){
    swap(n1, n2);
  }

  srand(time(0));
  answer = (rand() % (n2 - n1 + 1)) + n1;
  do {
    cout << "Enter guess: ";
    cin >> guess;
    cout << guess; //Echo Print

    if(guess > answer) cout << " - Too High" << endl;
    if(guess < answer) cout << " - Too Low" << endl;

    count++;
  }while(guess != answer);

  //OUTPUT
  cout << "\nCorrect, it took you " << count
       << " tries to guess my number." << endl;

  return 0;
}
