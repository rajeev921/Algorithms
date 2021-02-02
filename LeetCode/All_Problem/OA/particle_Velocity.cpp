#include <bits/stdc++.h>

using namespace std;

class Solution {
public: 
    int solution(vector<int>& nums) {
        int sz = nums.size();
        if( sz < 4)
            return 0;

        int totalPeriods = 0;

        for (int i = 0; i < sz; i++) {
            for (int count = 0; i + 2 < sz && nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]; i++) {
                count++;
                totalPeriods += count;
            }
        }
        return totalPeriods < 1000000000 ? totalPeriods : -1;
    }
};

// Another Unverified Solution
public int numberOfArithmeticSlices(int[] A) {
        // edge case
		if(A.length<3) return 0;
        
		// intial difference between first two elements
        int diff = A[1]-A[0];
		
		// total number of arithmetic slices found so far
        int slices = 0;
		
		// length of the current arithmetic slice
		// length of 1 denotes that there are 3 elements in the slice
        int len = 0;
        for(int i=2;i<A.length;i++) {
            if (A[i]-A[i-1] == diff) {
                len++;
				
				// Also, understand that as the length increases, the number of arith slices (a.s.) within that slices continues to grow.
				// For example:
				// [1,2,3] -> 1 a.s. 
				// [1,2,3,4] -> 1 + 2 a.s.
				// [1,2,3,4,5] -> 1 + 2 + 3 a.s.
				// and so on.
                slices += len;
            } else {
				// chain broken, reset diff and length
                diff = A[i] - A[i-1];
                len=0;
            }
        }
        return slices;
    }