class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        unordered_map<int, int> ctr;
    
        for (int i : nums1)
            ctr[i]++;
    
        for (int i : nums2)
            if (ctr[i]-- > 0)
                out.push_back(i);
        
        return out;
    }
};