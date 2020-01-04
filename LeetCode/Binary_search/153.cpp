class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        else if(nums.size()==1)
            return nums[0];
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right) {
            int mid = left + (right - left)/2;
            if(mid > 0 && nums[mid] < nums[mid-1]) {
                std::cout << nums[mid];
                return nums[mid];
            }
            else if(nums[left] <= nums[mid] && nums[mid] > nums[right]) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return nums[left];
    }
};