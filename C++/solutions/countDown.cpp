#include <iostream>
#include <thread>
#include <chrono>

int main() {

  std::cout << std::endl;

  for (int i = 10; i>0; --i) {
    std::cout << i << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
  }

  std::cout << std::endl;

}
