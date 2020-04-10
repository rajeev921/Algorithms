#include <cstring>
#include <iostream>

const char * min(const char * s, const char * t){
  return (strcmp(s,t) < 0) ? s: t;
}

float min(float x, float y){
  return (x<y) ? x: y;
}

int main(){

  std::cout << std::endl;

  std::cout << "min(abc, def):    " << min("abc", "def") << std::endl;
  std::cout << "min(4.5F, 1.23F): " << min(4.5F, 1.23F) << std::endl;
  std::cout << "min(2011, 2014):  " << min(2011, 2014) << std::endl;
  std::cout << "min(4.5, 1.23):   " << min(4.5, 1.23) << std::endl;
 
  std::cout << std::endl;

} 