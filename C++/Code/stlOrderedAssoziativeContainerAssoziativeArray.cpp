#include <iostream>
#include <map>
#include <stdexcept>

int main(){

  std::cout << std::endl;
  
  std::map<std::string, int> m { {"Dijkstra", 1972}, {"Meyers", 1976}, {"Ritchie", 0} };
  
  std::cout << "m[Stroustrup]: " <<  m["Stroustrup"] <<  std::endl;
  
  m["Stroustrup"]=1989;
  
  for(auto p : m) std::cout << '{' << p.first << ', ' << p.second << '}';
  
  m.erase("Meyers");
  
  std::cout << std::endl;
  
  for(auto p : m) std::cout << '{' << p.first << ', ' << p.second << '}';

  std::cout << std::endl;
  
  try{
    m.at("Sutter");
  }
  catch (const std::out_of_range& e){
    std::cerr << "Exception: " <<  e.what() << std::endl;
  }

  std::cout << std::endl;
}
