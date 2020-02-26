class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())
            return;
        next_permutation(nums.begin(), nums.end());
    }
};
/* Steps 
1. Find largest index i such that s[i-1] less than s[i].
2. If i is the first index of the string the permutation is the last permutation else s[i..n-1] 
is sorted in reverse order i.e. s[i-1] < s[i] >= s[i+1] >= s[i+2] >= ... >= s[n-1].
3. Find a highest index j to the right of index i such that s[j] is greater than s[i] and  swap 
charachter at index i with index j.
4. Reverse the substring s[i+1....n]
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2)
            return;
        
		int i = sz-2;
        
        while(i >= 0 && nums[i+1] <= nums[i])
            --i;

        if(i >= 0) {
            int j = nums.size()-1;
            while(j >= 0 && nums[j] <= nums[i])
                --j;
            swap(nums[i], nums[j]);
        }
		reverse(nums.begin()+i+1, nums.end());
    }
};
/*
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/