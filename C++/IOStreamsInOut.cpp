#include <fstream>
#include <iostream>
#include <string>

void writeFile(const std::string& name){

  std::ofstream outFile(name);

  if (!outFile){
    std::cerr << "Could not open file " << name << std::endl;
    exit(1);
  }

  outFile << "Line 1: Rainer Grimm" << std::endl;
  outFile << "Line 2: Beatrix Jaud-Grimm" << std::endl;
  outFile << "Line 3: Juliette Grimm" << std::endl;
  outFile << "Line 4: Marius Grimm" << std::endl;

}

void readFileShift(const std::string& name){

  std::ifstream inFile(name);

  if (!inFile){
    std::cerr << "Could not open file " << name << std::endl;
    exit(1);
  }
  while (inFile){
    std::string line;
    inFile >> line;
    std::cout << line << std::endl;
  }

}

void readFileGetline(const std::string& name){

  std::ifstream inFile(name);

  if (!inFile){
    std::cerr << "Could not open file " << name << std::endl;
    exit(1);
  }
  while (inFile){
    std::string line;
    std::getline(inFile, line);
    std::cout << line << std::endl;
  }

}

int main(){
  
  std::cout << std::endl;
  
  std::string grimm{"grimm.txt"};
  
  writeFile(grimm);
  std::cout << std::endl;
  readFileShift(grimm);
  std::cout << std::endl;
  readFileGetline(grimm);
  
  std::cout << std::endl;
}
