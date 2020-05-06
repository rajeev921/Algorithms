class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] == target) {
            return 0;
        } 
        else if(nums.size() < 2) {
            return -1;
        }
        int start = 0;
        int end = nums.size()-1;
    
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid]== target) {
                return mid;
            }
            if(nums[start] <= nums[mid]) {
                if(target >= nums[start] && target< nums[mid]) {
                    end = mid-1;
                }
                else {
                    start = mid+1;
                }
            }
            else if(target >= nums[mid] && target<= nums[end]) {
                start = mid+1;
            }
            else {
               end = mid-1;
            }
        }
        return -1;
    }
};


// Recursive Approach
class Solution {
public:
    int binary_search(vector<int>& nums, int start, int end, int target) 
    {
          if(start == end)
          {
              if(nums[start]==target)
              {
                    return start;
              }
              else
              {
                  return -1;
              }
          }
          // Check if middle element is same as the target.
          int mid = start + (end-start)/2;
          if(nums[mid] == target)
          {
              return mid;
          }
          else if(nums[start] <= nums[mid])
          {
                if(target >= nums[start] && target <= nums[mid])
                {
                    return binary_search(nums, start, mid-1, target);
                }
                return binary_search(nums, mid+1, end, target);
          }
          // pivot point is at the left of the middle element.
          else if(target >= nums[mid] && target <= nums[end])
          {
              return binary_search(nums, mid+1, end, target);
          }
          else
          {
              return binary_search(nums, start, mid-1, target);    
          }
    }
    
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
        return binary_search(nums, start, end, target);
    }
};
