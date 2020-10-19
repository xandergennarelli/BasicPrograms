/*
* Author: Xander Gennarelli
* Assignment Title:
* Assignment Description:
*
* Due Date: 10/21/2020
* Date Created: 10/19/2020
* Date Last Modified: 20/19/2020
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

#include <iostream>
#include <sstream>
#include <iomanip>
#include <array>
using namespace std;

int main(){
  //DATA ABSTRACTION / INPUT
  int size, max, rowMax, colDelta = 1;
  stringstream ss;

  while(cin >> size && size != 0){
    int mat[size][size];
    max = size / 2;
    if(size % 2 == 0){
      max++;
    }

    //PROCESS
    for(int i = 0; i < size; i++){
      rowMax = i + colDelta; //this is bullshit
      for(int j = 0; j < size; j++){
        // fuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuck me...
      }
    }
  }
  //OUTPUT


  return 0;
}
