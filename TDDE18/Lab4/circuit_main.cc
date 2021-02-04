#include "circuit.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int narg, char *argv[]){
  if(narg != 5){
    cout << "Number of parameters is incorrect. Exiting..." << endl;
    return 0;
  }
  int iterations;
  try{
    iterations = stoi(argv[1]);
  }catch(invalid_argument e){
    cerr << e.what() <<": first argument is invalid" << endl;
    return 0;
  }
  int prints;
  try{
    prints = stoi(argv[2]);
  }catch(invalid_argument e){
    cerr << e.what() <<": second argument is invalid" << endl;
    return 0;
  }
  double dt;
  try{
    dt = stod(argv[3]);
  }catch(invalid_argument e){
    cerr << e.what() <<": third argument is invalid" << endl;
    return 0;
  }
  double battery_voltage;
  try{
    battery_voltage = stod(argv[4]);
  }catch(invalid_argument e){
    cerr << e.what() <<": fourth argument is invalid" << endl;
    return 0;
  }

Connection P,N,L,R;
vector<Component*> circuit;
circuit.push_back(new Battery("V1", battery_voltage, P, N));
circuit.push_back(new Resistor("R1", 150.00, P, L));
circuit.push_back(new Resistor("R2", 50.00, P, R));
circuit.push_back(new Capacitor("C3", 1.00, 0.00, L, R));
circuit.push_back(new Resistor("R4", 300.00, L, N));
circuit.push_back(new Capacitor("C5", 0.75, 0.00, R, N));

simulate(circuit, iterations, prints, dt);

ifstream ifs("Circuit1.txt");

if(!ifs){
  cout<<"File was not found.\n";
  return 0;
}

    int i{0};
  string word{};
  string name;
  double value1;
  double value2;
  int n_nodes,n1,n2;

ifs>>word;
n_nodes = stoi(word);
vector<Connection> nodes[n_nodes];
vector<int> jj[n_nodes];
//for(int n=1; n<=n_nodes; n++) nodes.push_back(connection);

while (ifs>>word){
  if(word=="Battery"){
    cout << word << endl;
    while(ifs>>word){
      if(i==0)name=word;
      if(i==1)value1=stod(word);
      if(i==2)n1 = stoi(word);
      if(i==3)n2 = stoi(word);
      }
      i++;
    }
    //Connection x = nodes(1);
    //circuit.push_back(new Battery(name, value1, nodes[n1], nodes[n2]));

  if(word=="Resistor"){
  }
  if(word=="Capacitor"){
  }
  }



return 0;
}
