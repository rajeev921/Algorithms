#include <iostream>

int main(){

  double * myDouble = new double();
  void * myVoid = reinterpret_cast<void*>(myDouble);
  double * myDouble1 = reinterpret_cast<double*>(myVoid);

}
