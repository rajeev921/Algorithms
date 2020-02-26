/*
array can be 
empty
1 element
duplicate
+ve or -ve number
sorted
we can destroy original array

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2) {
            return sz;
        }
        
        int i{}, j{1};
        while(i < sz && j < sz) {
            if(nums[i]!=nums[j]){
                ++i;
                nums[i]=nums[j];
            }
            ++j;
        }
        nums.resize(i+1);
        
        return nums.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        
        int i = 0;
        for(int j = 0; j < nums.size(); ++j)
        {
            if(nums[i] != nums[j])
            {
                ++i;
                nums[i] = nums[j];
            }
        }
        //nums.erase(nums.begin()+i+1, nums.end());
        
        return i+1;
    }
};

// Method - 2 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        
        set<int> s(nums.begin(), nums.end());
        nums.assign(s.begin(), s.end());
        
        return nums.size();
    }
};
