// Time Complexity - O(n) , Space Complexity O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2) {
            if(sz==0)
                return 0;
            return nums[0];
        }
        unordered_map<int, int> lookup;
        
        for(int i{}; i < sz; ++i) {
            lookup[nums[i]]++;
            int temp = lookup[nums[i]];
            if(temp > sz/2)
                return nums[i];
        }
        return -1;
    }
};

// Time Complexity - O(n) , Space Complexity O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }else if(nums.size()==1){
            return nums[0];
        }
        
        int count{}, candidate{};        
        for(int num : nums) {
            if(count==0) {
                candidate = num;
            }
            count += (num==candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};