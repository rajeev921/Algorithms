class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() < 2) {
            return;
        }
        
        int j{};
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0)
                nums[j++] = nums[i];
        }
        
        for( ; j < nums.size(); ++j) {
            nums[j] = 0;   
        }

        return;
    }
};