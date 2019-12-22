#include <iostream>
#include <string>

// using directive
using namespace std;

namespace Date{
  int year{2014};
}
namespace Date{
  std::string month{"july"};
}

namespace Date2{
  std::string day{"sunday"};
}


int main(){

  cout << endl;

  // qualified
  cout << "year: " << Date::year << endl;
  cout << "month: " << Date::month << endl;

  // using declaration
  using Date::month;
  string myMonth{Date::month};
  string myMonth1{month};

  // using directive
  using namespace Date2;
  cout << day << endl;

  cout << endl;

}
