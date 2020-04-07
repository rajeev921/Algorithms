class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i{};
        int k{2}; // here k is variyaing to generalize the solution to work for any number of duplicate
        
        for(int n : nums){
            if(i < k || n > nums[i-k]) 
                nums[i++] = n;
        }
        
        return i;
    }
};
/*
[0,0,1,1,1,1,2,3,3],
[0,0,1,1,2,3,3]

*/