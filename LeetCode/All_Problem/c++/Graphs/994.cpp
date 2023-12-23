class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>> visited, int row, int col) {
        return 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) 
            return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> rotten;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) 
                    tot++;
                if(grid[i][j] == 2) 
                    rotten.push({i, j});
            }
        }
        
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cnt += k; 
            while(k--){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dir[i][0], ny = y + dir[i][1];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) 
                        continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            
            if(!rotten.empty())
                days++;
        }
        
        return tot == cnt ? days : -1;
    }
};
/*
--------------------------
[ [2, 1, 1],
  [1, 1, 0],
  [0, 1, 1] ] -> 4 
 --------------------------
[ [2, 1, 1],
  [0, 1, 1],
  [1, 0, 1] ] -> -1
--------------------------
[[0, 2]]      -> 0
--------------------------
0 - empty, 1 - fresh, 2 - rotten
*/
