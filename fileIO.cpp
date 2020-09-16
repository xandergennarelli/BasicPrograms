#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ofstream outputFile;
  ifstream inputFile;

  inputFile.open("name of file");
  if(!inputFile){
    cout << "Error: File Not Open";
    exit(1);
  }

  outputFile << "Hello world!" << endl;

  outputFile.close();
  return 0;
}
