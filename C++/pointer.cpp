#include <iostream>

void addOne(int& x){
  x += 1;
}

int main(){

  std::cout << std::endl;

  int i{2011};
  int* iptr= &i;

  std::cout << "iptr: " << iptr << std::endl;
  std::cout << "*iptr: " << *iptr << std::endl;

  std::cout << std::endl;

  int * jptr = iptr;
  *jptr = 2014;

  std::cout << "iptr: " << iptr << std::endl;
  std::cout << "*iptr: " << *iptr << std::endl;

  std::cout << "jptr: " << iptr << std::endl;
  std::cout << "*jptr: " << *iptr << std::endl;

  std::cout << std::endl;

  int intArray[] = {1, 2, 3, 4, 5};
  if (intArray[3] == *(intArray + 3)) std::cout << "Pointer arithmetic works" << std::endl;

  std::cout << std::endl;

  int* pi = nullptr;       // OK
  // int i = nullptr;      // ERROR
  bool b{nullptr};         // OK

  std::cout << std::boolalpha;
  std::cout << "b: " << b << std::endl;

  std::cout << std::endl;

  void (*inc1)(int&)= addOne;
  auto inc2 = addOne;

  int a{10};

  addOne(a);
  std::cout << "after addOne(a): " << a << std::endl;
  inc1(a);
  std::cout << "after inc1(a): "  << a << std::endl;
  inc2(a);
  std::cout << "after inc2(a): "  << a << std::endl;

  std::cout << std::endl;
}
