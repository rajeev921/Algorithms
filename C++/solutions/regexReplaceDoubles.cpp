#include <regex>
#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::string germanDoubles{"+0, 85 -13, 2 1, 0 , 45 -13, 7 1, 03425 10134, 25"};
  std::cout << germanDoubles << std::endl;

  // replace ", " with "."
  std::regex rgxDouble(R"(([-+]?[0-9]*), ?([0-9]+))");

  std::string englishDoubles{std::regex_replace(germanDoubles, rgxDouble, "$1.$2")};
  std::cout << englishDoubles << std::endl;

  std::cout << std::endl;

}
