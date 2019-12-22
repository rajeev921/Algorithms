#include <algorithm>
#include <iostream>
#include <vector>

int main(){
 
  std::cout << std::endl;
  
  std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto v: intVec) std::cout << v << " ";
  for (auto& v: intVec) v *= v;
  std::cout << std::endl;
  for (auto v: intVec) std::cout << v << " ";
  
  std::cout <<  "\n\n"; 
  intVec= {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int>::iterator beginIt;
  std::vector<int>::iterator endIt= intVec.end();
  for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); ++it) std::cout << *it << " "; 
  for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); ++it) (*it) *= (*it); 
  std::cout << std::endl;
  for (std::vector<int>::iterator it = intVec.begin(); it != intVec.end(); ++it) std::cout << *it << " "; 
  
  std::cout << "\n\n";
  
}

