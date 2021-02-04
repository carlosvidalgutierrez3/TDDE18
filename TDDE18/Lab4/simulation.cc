#include <vector>
#include <iostream>

main(){
  std::vector<int> circuit;

  circuit.push_back(1);
  circuit.push_back(2);

  for(int i=1; i<=circuit.size(); i++){
    std::cout << circuit[i] << ',';
  }


}
