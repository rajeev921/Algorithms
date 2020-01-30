class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()){
            cout <<" hello  ";
            return vector<vector<int>>{};
        }
        sort(nums.begin(), nums.end());    
        vector<vector<int>> result;
        
        do {
            result.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        
        return result;
    }
};

// Another Solution 

class Solution {
public:
    void permuteRecurse(vector<int>& nums, int start, vector<vector<int>>& res) {
        if(begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for(int i=start; i < nums.size(); ++i) {
            iter_swap(nums.begin()+start, nums.begin()+i);
            permuteRecurse(nums, start+1, res);
            iter_swap(nums.begin()+start, nums.begin()+i);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()){
            return vector<vector<int>>{};
        }
        vector<vector<int>> res;
        permuteRecurse(nums, 0, res);
        
        return res;
    }
};
// Time complexity : O(N!)

// https://leetcode.com/explore/interview/card/facebook/53/recursion-3/292/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)
// https://www.youtube.com/watch?v=GCm7m5671Ps

/*
Approach 1: Backtracking
Backtracking is an algorithm for finding all solutions by exploring all potential candidates. 
If the solution candidate turns to be not a solution (or at least not the last one), backtracking algorithm discards 
it by making some changes on the previous step, i.e. backtracks and then try again.

Here is a backtrack function which takes the index of the first integer to consider as an argument backtrack(first).

If the first integer to consider has index n that means that the current permutation is done.
Iterate over the integers from index first to index n - 1.
Place i-th integer first in the permutation, i.e. swap(nums[first], nums[i]).
Proceed to create all permutations which starts from i-th integer : backtrack(first + 1).
Now backtrack, i.e. swap(nums[first], nums[i]) back.

*/