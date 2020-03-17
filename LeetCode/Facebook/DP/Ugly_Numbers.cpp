#include <iostream>

using namespace std;

int findNthUgly(int n) 
{
	int len = 1;
	int i = 2;

	while(len < n) {
		if(i%2==0 || i%3==0 || i%5==0) {
			std::cout << i << " ";
			++len;
		}
		else{
			std::cout << "  else " <<i << " end  ";
		}
		++i;
	}
	return i-1;
}

int main()
{
	std::cout << findNthUgly(15);
	return 0;
}