#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(){

  std::cout << std::endl;

  std::istream_iterator<int> myIntStreamReader(std::cin);
  std::istream_iterator<int> myEndIterator;
  
   std::vector<int> myIntVec;
  
  while( myIntStreamReader != myEndIterator ){
    myIntVec.push_back( * myIntStreamReader);
    ++myIntStreamReader;
  }
  
  std::copy(myIntVec.begin(), myIntVec.end(),
	    std::ostream_iterator<int>(std::cout, ":"));
  
  
  std::cout << "\n\n";
}
  