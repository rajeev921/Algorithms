class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res(numRows);
        
        for(int i{}; i < numRows; ++i) {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;
            for(int j{1}; j<i; ++j) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
                }
        }
        return res;
    }
};
/*
    1 -      1
    2 -    1   1
    3 -  1   3   1
    4 - 1  4   4   1 
*/