#include <bits/stdc++.h>

using namespace std;

// TC - O(n)  , SC - O(n)
class Solution{
public:
    int lengthOfarrayRepLL(vector<int>& nums) {
        int sz = nums.size();
        if(sz < 2 || nums[0] == -1)
            return 0;
        
        int len{1};

        for(int idx{1}; idx < sz;) {
            idx = nums[idx];
            ++len;
            if(idx == -1)
                break;
        }

        return len;
    }
};

int main()
{
    vector<int> nums{1,4,-1,3,2};
                             
    Solution obj = Solution();
    
    cout << obj.lengthOfarrayRepLL(nums) << endl;
    return 0;
}

/*
    Finding the lengths of the array -> an array represents a linked list where index 0 represents the head. Example [1,4,-1,3,2], result will be 4 where:
    - Head has value of 1
    - 1 has value of 4
    - 4 has value of 2
    - 2 has value of -1 which ends the LL
*/