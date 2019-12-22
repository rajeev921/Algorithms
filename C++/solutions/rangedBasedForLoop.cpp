#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

static const int SIZE = 10;

int main(){

  std::cout << std::endl;

  std::vector<int> myContRange(10);

  int inc = 1;
  // for (int& i: myContRange) i = ++inc;
  std::iota(myContRange.begin(), myContRange.end(), 1);
  for (int i: myContRange) std::cout << i << " ";

  std::cout << std::endl;

  for (int& i: myContRange) i = (i*i);
  std::vector<int> myContForEach= myContRange;
  for (int i: myContRange) std::cout << i << " ";

  std::cout << std::endl;

  std::for_each( myContForEach.begin(), myContForEach.end(), [](int& i){return i*i;});
  for (int i: myContForEach) std::cout << i << " ";

  std::cout << "\n\n";

}
