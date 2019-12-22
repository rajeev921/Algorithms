#include <iostream>
#include <tuple>

std::tuple<int, int> divmod(int a, int b){
  return std::make_tuple( a / b, a % b);
}

int main(){

  std::cout << std::endl;

  auto res = divmod(10, 3);
  std::cout << "divmod(10, 3): " << "divmod(" << std::get<0>(res) << ", " <<  std::get<1>(res) << ")" << std::endl;

  std::cout << std::endl;

}
