#include <iostream>

using namespace std;

int main(){
  int *data = NULL;
  int size = 0, capacity = 2;
  int x; //temp int used for reading

  data = new int[capacity];

  while (cin >> x){
    if (size >= capacity){
      //resize
    }
    data[size] = x;
    size++;
  }

  return 0;
}
