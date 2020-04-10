#include <iostream>

class MeyersSingleton{

  private:

    MeyersSingleton() = default;
    ~MeyersSingleton() = default;

  public:

    MeyersSingleton(const MeyersSingleton&) = delete;
    MeyersSingleton& operator =(const MeyersSingleton&) = delete;

    static MeyersSingleton& getInstance(){
      static MeyersSingleton instance;
      return instance;
    }
};


int main(){

  std::cout << std::endl;

  std::cout << "&MeyersSingleton::getInstance(): "<< &MeyersSingleton::getInstance() << std::endl;
  std::cout << "&MeyersSingleton::getInstance(): "<< &MeyersSingleton::getInstance() << std::endl;

  std::cout << std::endl;

}

