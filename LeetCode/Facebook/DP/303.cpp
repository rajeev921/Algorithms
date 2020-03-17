class NumArray {
public:
    NumArray(vector<int>& nums) {
        dp.push_back(0);
        for(int val : nums) {
            dp.push_back(dp.back()+ val);
        }
            
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */