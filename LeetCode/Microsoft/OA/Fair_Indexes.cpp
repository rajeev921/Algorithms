#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int fairIndexWrap(vector<int>& A, vector<int>& B) {
        int res = 0, sumA = 0, sumB = 0;
        for(int i=0;i<A.size();i++) {
            sumA += A[i];
            sumB += B[i];
        }

        if (sumA != sumB || sumA % 2 != 0 || sumB % 2 != 0)    // if total sum of arrays are not equal or not even, then can't divide
            return 0;

        int tmpA = 0, tmpB = 0;
        for(int i=0;i<A.size()-1;i++) {
            tmpA += A[i];
            tmpB += B[i];
            if(sumA == 2 * tmpA && tmpA == tmpB)     // Only need to check either sumA or sumB is twice of tmpA or tmpB
                res++;
        }
        return res;
    }
    int fairIndex(vector<int>& A, vector<int>& B) {
        long leftSumA{}, rightSumA{}, leftSumB{}, rightSumB{};

        for(int i{}; i < A.size(); ++i) {
            rightSumA += A[i];
            rightSumB += B[i];
        }

        if (rightSumA != rightSumB || rightSumA % 2 != 0 || rightSumB % 2 != 0)    // if total sum of arrays are not equal or not even, then can't divide
            return 0;

        int res{};

        for(int i{}; i < A.size()-1; ++i) {
            leftSumA += A[i];
            leftSumB += B[i];

            rightSumA -= A[i];
            rightSumB -= B[i];

            if(leftSumA==leftSumB && rightSumA==rightSumB && leftSumA==rightSumA) 
                ++res;
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> A{{4, -1, 0, 3},
                          {2, -2, -3, 3},
                          {4, -1, 0, 3},
                          {3, 2, 6},
                          {1, 4, 2, -2, 5}};

    vector<vector<int>> B{{-2, 5, 0, 3},
                          {0, 0, 4, -4},
                          {-2, 6, 0, 4},
                          {4, 1, 6},
                          {7, -2, -2, 2, 5}};

    Solution obj = Solution();
    for(int i{}; i < A.size(); ++i){
        //cout << obj.fairIndex(A[i], B[i]) << endl;
        cout << obj.fairIndexWrap(A[i], B[i]) << endl;
    }
    
    return 0;
}