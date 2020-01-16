class Solution {
public:
    int maxProfit(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return 0;
        }
        int max = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            for(int j = i+1; j < nums.size(); ++j)
            {
                int k = nums[j] - nums[i];
                if(nums[i] < nums[j] && k > max)
                {
                    max = k;
                }
            }
        }
        return max;
    }
};

// Optimize Solution - Kadence Algorithm
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return 0;
        }
        int maxSo = 0, cur = 0;
        for(int i = 1; i < nums.size(); ++i) {
            cur = max(0, cur += nums[i] - nums[i-1]);
            maxSo = max(maxSo, cur);
        }
        return maxSo;
    }
};