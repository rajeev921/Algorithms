#include <cstddef>
#include <cstdlib>

#include <iostream>
#include <string>

class MyInt {
  int i;

public:
  MyInt(int ii) : i(ii) {
    std::cout << "constructor for: " << this << std::endl;
  }
  ~MyInt() {
    std::cout << "destructor for: " << this <<  std::endl;
  }
  void* operator new(std::size_t){
    std::cout << "operator new (default) " << std::endl;
    return static_cast<void*> (malloc(sizeof(MyInt)));
  }
  void* operator new(std::size_t, void* loc) {
    std::cout << "operator new (placement new) " << std::endl;
    return loc;
  }
};

char myIntBuf[sizeof(MyInt)];

int main(){

  std::cout << std::endl;

  std::string * onHeap = new std::string("on heap");

  char * buf = new char[100];
  std::string * inBuffer=  new(buf) std::string("in buffer");

  std::cout << "&inBuffer :" << static_cast<void*>(&inBuffer)  << std::endl;
  std::cout << "&onHeap :" << static_cast<void*>(&onHeap)  << std::endl;

  delete [] buf;
  delete onHeap;

  std::cout << std::endl;

  MyInt* myIntHeap = new MyInt(2011);
  delete myIntHeap;

  std::cout << std::endl;

  MyInt* myIntBuffer = new (myIntBuf) MyInt(2014);
  myIntBuffer->MyInt::~MyInt();                     // !! explicit destructor call

  std::cout << std::endl;

}
