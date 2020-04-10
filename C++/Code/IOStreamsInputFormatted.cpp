#include <iostream>

int main(){

  std::cout << std::endl;

  int a, b;
  std::cout << "Two natural numbers: " << std::endl;
  std::cin >> a >> b;
  std::cout << "a: " << a << " b: " << b << std::endl;

  std::cout << "\n\n";
  std::cout << "A sentence: " << std::endl;
  char ch;
  while (std::cin >> ch) std::cout << ch;

  std::cout << std::endl;

}
