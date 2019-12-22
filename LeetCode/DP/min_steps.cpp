#include <iostream>

using namespace std;

//Memoization
class Solution {
public:
	int dp[10]{0};
	int minSteps(int n)
	{
		std::cout << "Inside Func" << endl;
		if(n == 1)
			return 0;
		else if(dp[n] != 0) 
			return dp[n];
		int k = 1 + minSteps(n-1);
		std::cout <<"  " << k << endl;

		if(n%3 == 0) {
			k = min(k, minSteps(n/3)+1);	
			std::cout <<"n/3   " << k << endl;
		}
		if(n%2 == 0) {
			k = min(k, minSteps(n/2)+1);	
			std::cout <<"n/2   " << k << endl;
		}
		dp[n] = k;
		return k;
	}

};

// DP
class Solution2 {
public:
	int minSteps(int n) {
		int dp[n+1]{0};

		for(int i = 2; i < n+1; ++i) {
			dp[i] = 1 + dp[i-1];
			if(i%2 == 0)
				dp[i] = min(dp[i], dp[i/2]+1);
			if(i%3 == 0)
				dp[i] = min(dp[i], dp[i/3]+1);
		}
		return dp[n];
	}
};

int main()
{
	Solution2 sol;
	std::cout << sol.minSteps(7);

	return 0;
}