//testing pointers
#include <iostream>

int main(){
  int x{10};
  int* p = &x;
  *p = 66;
  //memory address:
  std::cout << "x = " << &x << "\np = " << p << '\n';
  delete p;
  //value:
  std::cout << "x = " << x << "\np = " << *p << '\n';

  return 0;
}
