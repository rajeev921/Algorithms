#include <iostream>


template <typename T = std::string, int Line = 10, int Column = Line>
class Matrix{
public:
  int numberOfElements() const;
};

template <typename T, int Line, int Column>
int Matrix<T, Line, Column>::numberOfElements() const {
  return Line * Column;
}


template <typename T>
class Matrix<T, 3, 3>{
public:
  int numberOfElements() const;
};

template <typename T>
int Matrix<T, 3, 3>::numberOfElements() const {
  return 3*3;
}


template <>
class Matrix<int, 3, 3>{
public:
  int numberOfElements() const;
};

int Matrix<int, 3, 3>::numberOfElements() const {
  return 3 * 3;
}

int main(){

  std::cout << std::endl;

  Matrix<double, 10, 5> matBigDouble;
  std::cout << "matBigDouble.numberOfElements(): " << matBigDouble.numberOfElements() << std::endl;

  // Matrix matString;    // ERROR
  Matrix<> matString;
  std::cout << "matString.numberOfElements(): " << matString.numberOfElements() << std::endl;

  Matrix<float> matFloat;
  std::cout << "matFloat.numberOfElements(): " << matFloat.numberOfElements() << std::endl;

  Matrix<bool, 20> matBool;
  std::cout << "matBool.numberOfElements(): " << matBool.numberOfElements() << std::endl;

  Matrix <double, 3, 3> matSmallDouble;
  std::cout << "matSmallDouble.numberOfElements(): " << matSmallDouble.numberOfElements() << std::endl;

  Matrix <int, 3, 3> matInt;
  std::cout << "matInt.numberOfElements(): " << matInt.numberOfElements() << std::endl;

  std::cout << std::endl;

}
