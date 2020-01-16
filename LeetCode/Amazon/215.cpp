// sort the array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        if(nums.size()==0 || k > nums.size()) {
            return -1;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        return nums[n-k];
    }
};

// priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        if(nums.size()==0 || k > nums.size()) {
            return -1;
        }
        
        priority_queue<int> pq;
        
        for(auto i : nums) {
            pq.push(i);
        }
        
        for(int i= 1; i < k; ++i) {
            pq.pop();
        }
        
        return pq.top();
    }
};

// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained
