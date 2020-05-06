class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ourVec; // Flatten 2D matrix to 1D matrix (vector)
        for (int i{}; i < matrix.size(); i++) {
            for (int j{}; j < matrix[0].size(); j++) {
                ourVec.push_back(matrix[i][j]);
            }
        }
        
        sort(ourVec.begin(), ourVec.end());
        
        return ourVec[k - 1];
    }
};

// More Optimal Solution - using priority queue

class Solution {
public:
    int kthSmallest(vector<vector<int>>& A, int B) {
        
        int n=A.size();
        
        int m=A[0].size();
        priority_queue<int> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(q.size()<B)
                    q.push(A[i][j]);
                else{
                    if(A[i][j]<q.top()){
                        q.pop();
                        q.push(A[i][j]);
                    }
                }
            }
        }
        return q.top();
    }
};
