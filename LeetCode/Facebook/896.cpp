#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int sz = A.size();
        if(sz < 2) {
            return true;
        }
        
        int first = A[0];
        int i{1};
        for(; i < sz; ++i) {
            int second = A[i];
            if(first > second) {
                break;
            }
            first = second;
        }
        if(i==sz){
            return true;
        }
        
        i=1;
        first= A[0];
        for(; i < sz; ++i) {
            int second = A[i];
            if(first < second) {
                break;
            }
            first = second;
        }
        if(i==sz){
            return true;
        }
        return false;
    }
};

int main()
{
	Solution obj;

	vector<int> A{2, 5, 8, 9, 55, 33};
	cout << obj.isMonotonic(A);

	return 0;
}
