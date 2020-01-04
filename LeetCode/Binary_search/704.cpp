class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] == target)
        {
            return 0;
        } 
        else if(nums.size() < 2)
        {
            return -1;
        }
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target > nums[mid])
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }   
        }
        return -1;
    }
};