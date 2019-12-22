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
