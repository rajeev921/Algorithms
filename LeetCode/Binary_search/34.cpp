class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size(), mid, left, right;
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] >= target)
                end = mid;
            else
                start = mid + 1;
            std::cout<<start<<"  "<<end<<"  "<<std::endl;
        }
        
        std::cout <<"new one "<< std::endl;
        left = start;
        start = 0, end = nums.size();
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                start = mid + 1;
            std::cout<<start<<"  "<<end<<"  "<<std::endl;
        }
        right = start;
        return left == right ? vector<int> {-1,-1} : vector<int> {left,right-1};
    }
};

// Use two binary search for upper bound and lower bound

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start{};
        int end = nums.size()-1;
        int left=-1, right=-1;
        
        // upper_bound
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target && (mid == end || nums[mid] != nums[mid+1])) {
                right = mid;
                break;
            }
            else if(nums[mid] > target) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        
        // lower_bound
        start = 0; 
        end = nums.size()-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target && ( mid == start || nums[mid] != nums[mid-1])) {
                left = mid;
                break;
            }
            else if(nums[mid] < target) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        
        return (right==left ? vector<int>{right, left} : vector<int>{left, right});
    }
};