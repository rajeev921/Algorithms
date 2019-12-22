#include <algorithm>
#include <iostream>
#include <vector>

int main(){

  std::cout << std::boolalpha << std::endl;

  std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 10};
  
  std::vector<int>::const_iterator myEndIt= myVec.end();
  std::vector<int>::const_iterator myVecIt;
  for (myVecIt = myVec.begin(); myVecIt != myEndIt; ++myVecIt) std::cout << *myVecIt << " ";
  
  std::cout << std::endl;
  
  std::vector<int>::reverse_iterator myLastIt = myVec.rbegin();
  *myLastIt = 9;

  for (myVecIt = myVec.begin(); myVecIt != myEndIt; ++myVecIt) std::cout << *myVecIt << " ";

  std::vector<int>::iterator myFindIt = std::find(myVec.begin(), myVec.end(), 5);
  std::cout << "(myVec[5] == *myFindIt): " << (myVec[4] == *myFindIt) << std::endl;
  
  myFindIt = std::find(myVec.begin(), myVec.end(), 2011);
  std::cout << "(myVec.end() == myFindIt): " << (myVec.end() == myFindIt) << std::endl;
  
  std::cout << "C++11: " << std::endl;
  
  


}