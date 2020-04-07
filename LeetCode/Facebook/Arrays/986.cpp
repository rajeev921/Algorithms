class Solution {
public:
        vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    for (auto i = 0, j = 0; i < A.size() && j < B.size(); A[i][1] < B[j][1] ? ++i : ++j) {
        auto start = max(A[i][0], B[j][0]);
        auto end = min(A[i][1], B[j][1]);
        if (start <= end) 
            res.push_back({start, end});
    }
    return res;    
    }
};
/*
A =  [[0,2],[5,10],[13,23],[24,25]], 
B = [[1,5],[8,12],[15,24],[25,26]]
    0 - 2 , 5 - 10 , 13 - 23 , 24 - 25
    1 - 5 , 8 - 12 , 15 - 24 , 25 - 26
-----------------------------------------
    1 - 2 , 5 - 5 , 8 - 10 , 15 - 23 , 24 - 24 , 25 - 25 
*/