#include <fstream>

using namespace std;

int main(){
  string fileName;
  ifstream inData;
  int sum = 0, count = 0, a;

  cout << "Enter a file name:: " << endl;
  cin >> fileName;

  inData.open(fileName);
  if(!inData){
    cout << "Error: File Not Open";
    exit(1);
  }

  while(inData >> a){
    count++;
    sum += a;
  }
  return 0;
}
