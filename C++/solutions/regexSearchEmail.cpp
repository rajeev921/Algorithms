#include <regex>
#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::string emailText = "A text with an email adresse: rainer@grimm-jaud.de.";

  // regular expression for the email address
  std::string regExprStr(R"(([\w.%+-]+)@([\w.-]+\.[a-zA-Z]{2, 4}))");

  // regular expression holder
  std::regex rgx(regExprStr);

  // search result holder
  std::smatch smatch;

  // searching for a match
  if (std::regex_search(emailText, smatch, rgx)){

    std::cout << "Text: " << emailText << std::endl;
    std::cout << std::endl;
    std::cout << "Before the email address: " << smatch.prefix() << std::endl;
    std::cout << "After the email address: " << smatch.suffix() << std::endl;
    std::cout << std::endl;
    std::cout << "Length of email adress: " << smatch.length() << std::endl;
    std::cout << std::endl;
    std::cout << "Email address: " << smatch[0] << std::endl;
    std::cout << "Local part: " << smatch[1] << std::endl;
    std::cout << "Domain name: " << smatch[2] << std::endl;

  }

  std::cout << std::endl;

}
