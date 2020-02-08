class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if(grid.size() < 2){
            if(grid.size()==1 && grid[0].size()==1){
                return grid[0][0];
            }
            else if(grid.size()==0) {
                return 0;
            }
        }
    
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = grid[0][0];
        
        for(int i=1; i < row; ++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];    
        
        for(int i=1; i < col; ++i)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        
        if(row==1){
            return dp[0][col-1];    
        }
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
};

// Another solution With space complexity - O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        for (int j = 1; j < n; j++) {
  9          cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};
