
// setfill example
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setfill, std::setw

int main () {
  std::cout << 10;
  std::cout << std::setfill ('x') << std::setw (10) << std::endl;
  return 0;
}
