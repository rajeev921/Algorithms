#include <iostream>
#include <string>

class Account{};

template<typename T>
struct Type{
  std::string getName() const {
    return "unknown";
  }
};

template<>
struct Type<int>{
  std::string getName() const{
    return "int";
  }
};

template<>
struct Type<double>{
  std::string getName() const{
    return "double";
  }
};

template<>
struct Type<std::string>{
  std::string getName() const{
    return "std::string";
  }
};

template<>
struct Type<Account>{
  std::string getName() const{
    return "Account";
  }
};

template <typename T>
T min(T fir, T sec){
  Type<T> t;
  std::cout << t.getName() << std::endl;
  return (fir < sec) ? fir : sec;
}

template <>
bool min<bool>(bool fir, bool sec){
  std::cout << "bool" << std::endl;
  return fir & sec;
}

int main(){

  std::cout << std::boolalpha << std::endl;

  Type<float> tFloat;
  std::cout << "tFloat.getName(): " << tFloat.getName() << std::endl;

  Type<double> tDouble;
  std::cout << "tDouble.getName(): " << tDouble.getName() << std::endl;

  Type<std::string> tString;
  std::cout << "tString.getName(): " << tString.getName() << std::endl;

  Type<int> tInt;
  std::cout << "tInt.getName(): " << tInt.getName() << std::endl;

  Type<Account> tAccount;
  std::cout << "tAccount.getName(): " << tAccount.getName() << std::endl;

  std::cout << std::endl;

  std::cout << "min(3.5, 4, 5): "  << min(3.5, 4.5) << std::endl;
  std::cout << "min<double>(3.5, 4, 5): "  << min<double>(3.5, 4.5) << std::endl;

  std::cout << "min(true, false): "  << min(true, false) << std::endl;
  std::cout << "min<bool>(true, false): "  << min<bool>(true, false) << std::endl;

  std::cout << std::endl;

}
