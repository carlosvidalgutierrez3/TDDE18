//TODO: Use only one try/cath block and catch each exception. DONE
//TODO: DO not print to std out. DONE
//TODO: Use appropriate return value for failure. return (int) of appropriate value. DONE

#include "circuit.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int narg, char *argv[]){
  if(narg != 5){
    cerr << "Number of parameters is incorrect. Exiting..." << endl;
    return 1;
  }
  int iterations;
  int prints;
  double dt;
  double battery_voltage;
  try{
    iterations = stoi(argv[1]);
    prints = stoi(argv[2]);
    dt = stod(argv[3]);
    battery_voltage = stod(argv[4]);
  }
  catch(invalid_argument e){
    cerr << e.what() <<": Invalid argument" << endl;
    return 1;
  }

vector<Component*> circuit;

Connection P,N,r124, r125;
circuit.push_back(new Battery("V1", battery_voltage, P, N));
circuit.push_back(new Resistor("R1", 6.00, P, r124));
circuit.push_back(new Resistor("R2", 4.00, r124, r125));
circuit.push_back(new Resistor("R3", 8.00, r125, N));
circuit.push_back(new Resistor("R4", 12.00, r124, N));

/*Connection P,N,L, R;
circuit.push_back(new Battery("V1", battery_voltage, P, N));
circuit.push_back(new Resistor("R1", 150.00, P, L));
circuit.push_back(new Resistor("R2", 50.00, P, R));
circuit.push_back(new Resistor("R3", 100.00, L, R));
circuit.push_back(new Resistor("R4", 300.00, L, N));
circuit.push_back(new Resistor("R5", 250.00, R, N));*/

/*Connection P,N,L,R;
circuit.push_back(new Battery("V1", battery_voltage, P, N));
circuit.push_back(new Resistor("R1", 150.00, P, L));
circuit.push_back(new Resistor("R2", 50.00, P, R));
circuit.push_back(new Capacitor("C3", 1.00, 0.00, L, R));
circuit.push_back(new Resistor("R4", 300.00, L, N));
circuit.push_back(new Capacitor("C5", 0.75, 0.00, R, N));*/

simulate(circuit, iterations, prints, dt);

return 0;
}
