class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 3)
            return {};
        
        sort(nums.begin(), nums.end());   // O(nlogn)
        vector<vector<int>> res;
        for(int i{}; i < sz-2; ++i){     // O(n^2)
            if (i > 0 && (nums[i] > 0 || nums[i] == nums[i - 1]) )
                continue;
            int j = i+1;
            int k = sz -1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) 
                    --k;
                else if (sum < 0)
                    ++j;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[k]==nums[k-1])
                        --k;
                    while(j < k && nums[j]==nums[j+1])
                        --j;
                    --k;
                    ++j;
                }
            }
        }
        
        return res;
    }
};
/*
nums = [-1, 0, 1, 2, -1, -4],
i = 0
-1 + 0 + -4 = -5
-1 + 1 + -4 = -4
-1 + 2 + -4 = -3
-1 + -1 + -4 = -6
i = 1
0 + 1 + -4 = -3 
0 + 2 + -4 = -2
0 + -1 + -4 = -5
0 + 




Solution :
[
  [-1, 0, 1],
  [-1, -1, 2]
]

// Array can contain 
    duplicate, 
    -ve number, 
    can be empty, 
    Do not destroy the original array
    size smaller than 3 
        return empty vector
*/