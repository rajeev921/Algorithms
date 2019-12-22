#include <iostream>

template<typename T1, typename T2>
auto add(T1 fir, T2 sec){ return fir + sec; }

int main(){
  
  std::cout << add(1, 2) << std::endl;
  std::cout << add (1, 2ll) << std::endl;

  auto res = add(1, 2.0);
  std::cout << res << std::endl;

}
