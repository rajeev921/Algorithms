#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main(){

  std::cout << std::endl;

  
  std::set<int> mySet{5, 1, 4, 3, 2, 7, 6};
  for (auto s: mySet) std::cout << s << " ";
  
  std::cout << "\n\n";
  
  std::map<int, std::string, std::greater<int>> int2Str{ {5, "five"}, {1, "one"}, {4, "four"}, {3, "three"}, {2, "two"}, {7, "seven"}, {6, "six"} };
  for (auto p: int2Str) std::cout << "{" << p.first << ", " << p.second << "} "; 
  
  std::cout << "\n\n";

}
