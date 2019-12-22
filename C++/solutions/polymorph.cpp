#include <iostream>

struct Base{
    virtual void interface(){
        std::cout << "Implementation Base" << std::endl;
    }
};

struct Derived1: Base{
    virtual void interface(){
        std::cout << "Implementation Derived1" << std::endl;
    }
};

struct Derived2: Base{
    virtual void interface(){
        std::cout << "Implementation Derived2" << std::endl;
    }
};

struct Derived3: Base{};


void execute(Base& base){
    base.interface();
}


int main(){

    std::cout << std::endl;

    Derived1 d1;
    Base& b1 = d1;
    execute(b1);

    Derived2 d2;
    Base& b2 = d2;
    execute(b2);

    Derived3 d3;
    Base& b3 = d3;
    execute(b3);
    
    std::cout << std::endl;

}
