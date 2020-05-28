#include <bits/stdc++.h>

using namespace std;

// TC - O(n)  , SC - O(n)
class Solution{
public:
    int largestNumberX(vector<int>& nums) {
        
        unordered_map<int, int> lookup;
        int res{};

        for(auto val : nums) {
            ++lookup[val];
        }

        for(auto itr = lookup.begin(); itr != lookup.end(); ++itr) {
            if(itr->first == itr->second) {
                res = max(res, itr->second);
                //cout << itr->first <<"   "<< itr->second << endl;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> nums{{3, 8, 2, 3, 3, 2},
                             {7, 1, 2, 8, 2},
                             {3, 1, 4, 1, 5},
                             {5, 5, 5, 5, 5}};

    Solution obj = Solution();
    
    for(auto num : nums){
        cout << obj.largestNumberX(num);
        cout <<"New List Procesing   " << endl;
    }
    
    return 0;
}