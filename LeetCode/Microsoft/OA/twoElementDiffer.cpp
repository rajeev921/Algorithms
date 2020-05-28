#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool twoElementDiffer(vector<int>& nums) {
        unordered_set<int> st;

        for(auto val : nums) {
            if(st.find(val-1)!= st.end() || st.find(val+1)!= st.end())
                return true;
            st.insert(val);
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> nums{{7},
                             {4, 3},
                             {11, 1, 8, 12, 14},
                             {5, 5, 5, 5, 5},
                             {4, 10, 8, 5, 9} };

    Solution obj = Solution();
    for(auto num : nums){
        cout << obj.twoElementDiffer(num) << endl;
    }

    return 0;
}