class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return nums[0];
        }
        int maxSo = INT_MIN, cur = 0;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            cur= max(nums[i], cur+nums[i]);
            maxSo = max(cur, maxSo);
        }
        
        return maxSo;
    }
};