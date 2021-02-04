#ifndef PERRO_H
#define PERRO_H
#include <iostream>
#include <string>

using namespace std;

class Animal{
public:
  Animal();
  Animal(string name);
  //virtual void make_sound() = 0;
protected:
  string name{};
};

class Dog : public Animal{
public:
  Dog(string name);
  //void make_sound();
  bool is_good_boy{};
};

#endif
