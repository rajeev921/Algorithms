class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start  = 0, end = nums.size()-1;
        int index = -1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
            {
                index = mid;
                break;
            }
            else if(nums[mid]>target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return index==-1 ? start : index;
    }
};