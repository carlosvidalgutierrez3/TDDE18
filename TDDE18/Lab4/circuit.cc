#include "circuit.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


Component::Component(std::string name, Connection &a, Connection &b)
:name{name}, a{a}, b{b} { }


double Component::get_voltage(){
  return this->a.charge-this->b.charge;
}

Battery::Battery(string name, double voltage, Connection &a, Connection &b)
:Component (name, a, b) {
  this->voltage=voltage;
}
double Battery::current(){
  return 0.0;
}
void Battery::simulate(double dt){
  this->a.charge=this->voltage;
  this->b.charge=0;
}



Resistor::Resistor(string name, double resistance, Connection &a, Connection &b)
:Component (name, a, b) {
  this->resistance=resistance;
}

void Resistor::simulate(double dt){
  double incremento{(this->get_voltage()/this->resistance)*dt};
  this->b.charge=this->b.charge+incremento;
  this->a.charge=this->a.charge-incremento;
}
double Resistor::current(){
  return (this->get_voltage())/this->resistance;
}

Capacitor::Capacitor(string name, double farad, double load, Connection &a, Connection &b)
:Component (name, a, b) {
  this->farad=farad;
  this->load=load;
}
double Capacitor::current(){
  return this->farad*(this->get_voltage() - this->load);
}
void Capacitor::simulate(double dt){
  double incremento{this->farad*((this->a.charge-this->b.charge)-this->load)*dt};
  this->b.charge=this->b.charge+incremento;
  this->a.charge=this->a.charge-incremento;
  this->load=this->get_voltage();
}


void simulate (vector<Component*> circuit, int iterations, int n_outputs, double dt)
{
  for(auto element:circuit){
    cout << setw(12) << element->name;
  }
  cout << endl;
  for(auto element:circuit){
    cout << setw(7) << "Volt";
    cout << setw(5) << "Curr";
  }
  cout << endl;
  for(int i{0};i<iterations;i++){
    for(auto element:circuit){
      element->simulate(dt);
      if(i%(iterations/n_outputs)==0){
        cout << fixed << setprecision(2) << setw(7) << abs(element->get_voltage());
        cout << fixed << setprecision(2) << setw(5) << abs(element->current());
      }
    }
    if(i%(iterations/n_outputs)==0){
      cout << endl;
    }
  }
}
