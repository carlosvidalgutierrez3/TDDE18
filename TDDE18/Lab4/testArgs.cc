#include <vector>
#include <string>
#include <iostream>


using namespace std;

int main(int narg, char *argv[]){
  if(narg != 5){
    cout << "Number of parameters is incorrect. Exiting..." << endl;
    return 0;
  }
  int "name" = 1;
  
  cout << "Iterations: " << argv[1] << endl;
  int iterations{stoi(argv[1])};
  iterations = iterations + 10;
  cout << "iterations + 10: " << iterations << endl;
  cout << "Dt: " << argv[3] << endl;
  double dt{atof(argv[3])};
  dt = dt+10.1;
  cout << "dt + 10: " << dt << endl;
  return 0;
}
