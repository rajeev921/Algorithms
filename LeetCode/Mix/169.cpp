// Time Complexity - O(n) , Space Complexity O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }else if(nums.size()==1){
            return nums[0];
        }
        
        unordered_map<int, int> lookup;
        int ret;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(lookup.find(nums[i]) == lookup.end()) {
                lookup[nums[i]] = 1;
            }else{
                lookup[nums[i]] += 1;
            }
        }
        
        for(auto itr=lookup.begin(); itr != lookup.end(); itr++) {
            if(itr->second > nums.size()/2) {
                ret = itr->first;
            }    
        }
        
        return ret;
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