#include <iostream>

class HelloGoodBye{
public:
  HelloGoodBye(int i):numb(i){
    std::cout << "Hello from " << numb << ": "<< std::endl;
  }
  ~HelloGoodBye();
private:
  int numb;
};

HelloGoodBye::~HelloGoodBye(){
  std::cout << "Good Bye from : " <<  numb << std::endl;
}

void func(){
  HelloGoodBye helloGoodBye(5);
}

HelloGoodBye helloGoodBye(1);

int main(){

  std::cout << std::endl;

  HelloGoodBye helloGoodBye(2);

  std::cout << std::endl;

  HelloGoodBye* helloGoodByePtr = new HelloGoodBye(3);

  std::cout << std::endl;

  {
    HelloGoodBye helloGoodBye(4);
  }

  std::cout << std::endl;

  delete helloGoodByePtr;

  func();

  std::cout << "--------- End of main ----------"  << std::endl;

}
