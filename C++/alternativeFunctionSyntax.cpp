#include <iostream>

int sumOld(int a, int b){
  return a + b;
}

auto sumNew(int a, int b)->int {
  return a + b;
}

int main(){

  std::cout << std::endl;

  std::cout << "sumOld(2, 3): " << sumOld(2, 3) << std::endl;
  std::cout << "sumNew(2, 3): " << sumOld(2, 3) << std::endl;

  std::cout << std::endl;

}
