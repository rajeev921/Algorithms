#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

int main(){

  std::cout << std::endl;

  std::deque<int> myDeq{5, 6, 7, 10, 11, 12};

  for (auto d: myDeq) std::cout << d << " ";
  
  std::cout << std::endl;

  std::vector<int> tmpVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  std::copy(std::find(tmpVec.begin(), tmpVec.end(), 13), tmpVec.end(),  std::back_inserter(myDeq));
  
  for (auto d: myDeq) std::cout << d << " ";
  
  std::cout << std::endl;
  
  std::copy(std::find(tmpVec.begin(), tmpVec.end(), 8), std::find(tmpVec.begin(), tmpVec.end(), 10),  
	    std::inserter(myDeq, std::find(myDeq.begin(), myDeq.end(), 10)));
  
  for (auto d: myDeq) std::cout << d << " ";
  
  std::cout << std::endl;
  
  std::copy(tmpVec.rbegin()+11, tmpVec.rend(),  
	    std::front_inserter(myDeq));
   
  for (auto d: myDeq) std::cout << d << " ";

  std::cout << std::endl;

}