/*
Given an array nums and a target value k, find the maximum 
length of a subarray that sums to k. If there isn't one, 
return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.

Example 2:
Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?
*/

/* 
[1, -1, 5, -2, 3], k = 3
1
(1-1)=0, (1-1+5)=5, (1-1+5-2)=3, (1-1+5-2+3) = 6
		  (-1+5)=4, (-1+5-2)=2,  (-1+5-2+3)  = 5
					(5-2)   =3,  (5-2+3)     = 6
					             (-2+3)      = 1
[1, 0, 5, 3, 6] 								 

*/

// Time Complexity - O(n^2) , Space - O(n)
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
		int maxlen{}, acc{};
        unordered_map<int, int> lookup;
        lookup[0] = -1;
        
		for(int i{}; i < nums.size(); ++i) {
		    acc += nums[i];
            if(lookup.find(acc-k) != lookup.end()) {
                maxlen = max(maxlen, i - lookup.at(acc-k));    
            }
            if(lookup.find(acc) == lookup.end()) {
                lookup[acc]=i;    
            }
		}
		
		return maxlen;
    }
};
