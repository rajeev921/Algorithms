#include <iostream>
#include <typeinfo>

int main(){

  std::cout << std::endl;

  int i{2011};
  const int* constI = const_cast<const int*>(&i);
  int* nonConstI = const_cast<int*>(constI);
  *nonConstI = 9000;
  
  std::cout << "i: " << i << std::endl;
  
  std::cout << std::endl;

  std::cout << "typeid(constI).name(): " << typeid(constI).name() << std::endl;
  std::cout << "typeid(nonConstI).name(): " << typeid(nonConstI).name() << std::endl;

  std::cout << std::endl;

}
