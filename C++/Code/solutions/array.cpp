#include <array>
#include <iostream>

int main(){

  std::cout << std::endl;

  std::array<int, 4> arr = {1, 2, 3, 4};

  for (auto a: arr){ std::cout << a << " " ; }

  arr[1]=1000;
  arr[5]=5;

  std::cout << std::endl;

  for (auto a: arr){ std::cout << a << " " ; }

  arr.at(0) = 10000;
  arr.at(5) = 5;

  std::cout << std::endl;

}
