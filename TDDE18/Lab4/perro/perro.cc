#include <iostream>
#include <string>
#include "perro.h"

using namespace std;

Animal::Animal() : name(""){}
Animal::Animal(string name) : name{name}{}

//Animal::virtual void make_sound() = 0;


Dog::Dog(string name) : Animal{name}{
  this->is_good_boy = true;
}//, is_good_boy{true}{}
//Dog::void make_sound() override {cout << "imma dog" << endl;}
//Dog::bool is_good_boy{true};
