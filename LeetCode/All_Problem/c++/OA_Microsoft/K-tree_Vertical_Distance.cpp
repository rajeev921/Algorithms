#include <bits/stdc++.h>

using namespace std;

// TC - O(n)  , SC - O(n)
class Solution{
public:
    int findVerticalPath(vector<int>& nums) {
        int maxWidth{};
        
        unordered_set<int> st;
        copy(nums.begin(), nums.end(), inserter(st, st.end()));
        copy(st.begin(), st.end(), nums.begin());
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-1; i++) {
            maxWidth = max(maxWidth, (nums[i+1] - nums[i]));
        }
        return maxWidth;
    }
};

int main()
{
    vector<vector<int>> nums{{5, 5, 5, 7, 7, 7},
                             {6, 10, 1, 4, 3},
                             {4, 1, 5, 4}
                             };

    Solution obj = Solution();
    
    for(auto num : nums){
        cout << obj.findVerticalPath(num)<< endl;
    }
    
    return 0;
}