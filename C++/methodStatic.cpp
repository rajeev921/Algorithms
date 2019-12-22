#include <iostream>

class Account{
public:
    Account(){
      ++deposits;
    }
    static int getDeposits(){
      return Account::deposits;
    }

private:
    static int deposits;
};

int Account::deposits= 0;

int main(){

  std::cout << std::endl;

  std::cout << "Account::getDeposits(): "  << Account::getDeposits() << std::endl;

  Account account1;
  Account account2;

  std::cout << "account1.getDeposits(): "  << account2.getDeposits() << std::endl;
  std::cout << "account2.getDeposits(): "  << account1.getDeposits() << std::endl;
  std::cout << "Account::getDeposits(): "  << Account::getDeposits() << std::endl;

  std::cout << std::endl;

}


