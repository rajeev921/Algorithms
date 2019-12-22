#include <iostream>
#include <type_traits>

int main(){

  std::cout << std::boolalpha << std::endl;

  std::cout << "std::is_const<std::add_const<int>::type>::value: " <<  std::is_const<std::add_const<int>::type>::value << std::endl;
  std::cout << "std::is_const<std::remove_const<const int>::type>::value: " << std::is_const<std::remove_const<const int>::type>::value << std::endl;

  std::cout << std::endl;
  typedef std::add_const<int>::type myConstInt;
  std::cout << "std::is_const<myConstInt>::value: " << std::is_const<myConstInt>::value << std::endl;
  typedef const int myConstInt2;
  std::cout << "std::is_same<myConstInt, myConstInt2>::value: " << std::is_same<myConstInt, myConstInt2>::value << std::endl;

  std::cout << std::endl;

  int fir = 1;
  int& refFir1 = fir;
  using refToIntType = typename std::add_lvalue_reference<int>::type;
  refToIntType refFir2= fir;

  std::cout << "(fir, refFi1r, refFir2): "  << "(" << fir << ", " << refFir1 << ", " << refFir2 << ")" << std::endl;

  fir = 2;

  std::cout << "(fir, refFir, refFir2): "  << "(" << fir << ", " << refFir1 << ", " << refFir2 << ")" << std::endl;

  std::cout << std::endl;

}
