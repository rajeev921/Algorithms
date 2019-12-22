#include <condition_variable>
#include <iostream>
#include <thread>

bool dataReady= false;

std::mutex mutex_;
std::condition_variable condVar1;
std::condition_variable condVar2;

int counter = 0;
int COUNTLIMIT = 50;

void setTrue(){

  while(counter <= COUNTLIMIT){

    std::unique_lock<std::mutex> lck(mutex_);
    condVar1.wait(lck, []{return dataReady == false;});
    dataReady = true;
    ++counter;
    std::cout << dataReady << std::endl;
    condVar2.notify_one();

  }
}

void setFalse(){

  while(counter < COUNTLIMIT){

    std::unique_lock<std::mutex> lck(mutex_);
    condVar2.wait(lck, []{return dataReady == true;});
    dataReady = false;
    std::cout << dataReady << std::endl;
    condVar1.notify_one();

  }

}

int main(){

  std::cout << std::boolalpha << std::endl;

  std::cout << "Begin: " << dataReady << std::endl;

  std::thread t1(setTrue);
  std::thread t2(setFalse);

  t1.join();
  t2.join();
  
  dataReady = false;
  std::cout << "End: " << dataReady << std::endl;

  std::cout << std::endl;
}


