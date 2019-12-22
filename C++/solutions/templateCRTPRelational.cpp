#include <iostream>
#include <string>
#include <utility>

template<class Derived>
class Relational{};

// Relational Operators

template <class Derived>
bool operator > (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return d2 < d1;
}

template <class Derived>
bool operator == (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return !(d1 < d2) && !(d2 < d1);
}

template <class Derived>
bool operator != (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 < d2) || (d2 < d1);
}

template <class Derived>
bool operator <= (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 < d2) || (d1 == d2);
}

template <class Derived>
bool operator >= (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 > d2) || (d1 == d2);
}

// Apple

class Apple: public Relational<Apple>{
public:
    Apple(int s): size{s}{};
    friend bool operator < (Apple const& a1, Apple const& a2){
        return a1.size < a2.size;
    }
private:
    int size;
};

// Man

class Man: public Relational<Man>{
public:
    Man(std::string n): name{n}{}
    friend bool operator < (Man const& m1, Man const& m2){
        return m1.name < m2.name;
    }
private:
    std::string name;
};

// class Person
class Person: public Relational<Person>{
public:
    Person(std::string fst, std::string sec): first(fst), second(sec){}
    friend bool operator < (Person const& p1, Person const& p2){
        return std::make_pair(p1.first, p2.second) < std::make_pair(p2.first, p2.second);
    }
private:
    std::string first;
    std::string second;
};
        

int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  Apple apple1{5};
  Apple apple2{10}; 
  std::cout << "apple1 < apple2: " << (apple1 < apple2) << std::endl;
  std::cout << "apple1 > apple2: " << (apple1 > apple2) << std::endl;
  std::cout << "apple1 == apple2: " << (apple1 == apple2) << std::endl;
  std::cout << "apple1 != apple2: " << (apple1 != apple2) << std::endl;
  std::cout << "apple1 <= apple2: " << (apple1 <= apple2) << std::endl;
  std::cout << "apple1 >= apple2: " << (apple1 >= apple2) << std::endl;
  
  std::cout << std::endl;
    
  Man man1{"grimm"};
  Man man2{"jaud"};
  std::cout << "man1 < man2: " << (man1 < man2) << std::endl; 
  std::cout << "man1 > man2: " << (man1 > man2) << std::endl; 
  std::cout << "man1 == man2: " << (man1 == man2) << std::endl; 
  std::cout << "man1 != man2: " << (man1 != man2) << std::endl;
  std::cout << "man1 <= man2: " << (man1 <= man2) << std::endl;
  std::cout << "man1 >= man2: " << (man1 >= man2) << std::endl;
  
  std::cout << std::endl;
  
  Person rainer{"Rainer", "Grimm"};
  Person marius{"Marius", "Grimm"};
  std::cout << "rainer < marius: " << (rainer < marius) << std::endl; 
  std::cout << "rainer > marius: " << (rainer > marius) << std::endl; 
  std::cout << "rainer == marius: " << (rainer == marius) << std::endl; 
  std::cout << "rainer != marius: " << (rainer != marius) << std::endl;
  std::cout << "rainer <= marius: " << (rainer <= marius) << std::endl;
  std::cout << "rainer >= marius: " << (rainer >= marius) << std::endl;
  
  
  
  
  std::cout << std::endl;
    
}
