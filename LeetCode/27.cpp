/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
*/

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int count = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); ++j)
        {
            if(nums[j] != val)
            {
               nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};

/*

The distance(first, last) function tells you how many items are between the iterator at first and last. 
Note that pointers are iterators, random-access iterators to be specific. So the distance between one pointer 
and another is their difference, as defined by operator-.

*/
int removeElement(vector<int>& nums, int val) {
    return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
}