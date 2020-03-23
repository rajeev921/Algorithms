class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        if(nums.size() < 2) {
            return vector<int>{};
        }
        unordered_map<int, int> umap;
        
        for(int i = 0; i < nums.size(); ++i) {
            auto ptr = umap.find(target-nums[i]);
            if(ptr != umap.end())
            {
                return vector<int>{ptr->second , i};
            }
            umap[nums[i]] = i;
        }
        
        return vector<int>{};
    }    
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res{};
        if(nums.size() < 1) {
            res;
        }
        
        unordered_map<int, int> lookup;
        
        for(int i = 0; i < nums.size(); ++i) {
            auto ptr = lookup.find(target-nums[i]);
            if(ptr != lookup.end()) {
                return vector<int>{i, ptr->second};
            }
            else{
                lookup[nums[i]] = i;
            }
        }
        
        return res;
    }
};
/*
2, 7, 11, 15 target = 9
    2+7 = 9
    return {0, 1}

if array is 0 and 1 return empty vector
if nothing found return same;
array is sorted or not
array is containing -ve , duplicate 

*/


