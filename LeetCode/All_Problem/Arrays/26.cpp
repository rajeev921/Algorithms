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
        
        int x{}, i{};
        for(; i < sz; ++i) {
            if(nums[i] != nums[x]){
                nums[++x]=nums[i];
            }
        }
        nums.resize(x+1);
        //nums.erase(nums.begin()+i+1, nums.end());

        return x+1;
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
