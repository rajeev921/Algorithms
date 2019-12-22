#include <iostream>

class Account{
public:
  Account(){
    std::cout << "Account: this: "  << this << std::endl;
  };
  Account(double){
    std::cout << "Account(double): this: "  << this << std::endl;

  }
};

int main(){

   std::cout << std::endl;

   Account account1;
   Account* account2 = new Account;

   std::cout << std::endl;

   Account account3(100.0);
   Account* account4 = new Account(100.0);

   std::cout << std::endl;

   Account* accountArray = new Account[10];

   std::cout << std::endl;

}
