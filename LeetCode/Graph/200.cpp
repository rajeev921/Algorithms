class Solution {
public:
    int bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        
        queue<pair<int,int>> q;
        q.push(make_pair(row, col));
        visited[row][col] = 1;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                pair<int, int> p = q.front();
                int row = p.first;
                int col = p.second;
                q.pop();
                if(row+1 != grid.size() && visited[row+1][col] == 0 && grid[row+1][col] == '1') {   
                    q.push(make_pair(row+1, col));
                    visited[row+1][col] = 1;
                }
                if(col+1 != grid[0].size() && visited[row][col+1] == 0 && grid[row][col+1] == '1') {
                    q.push(make_pair(row, col+1));
                    visited[row][col+1] = 1;
                }
                if(col != 0 && col-1 >= 0 && visited[row][col-1] == 0 && grid[row][col-1] == '1') {
                    q.push(make_pair(row, col-1));
                    visited[row][col-1] = 1;
                }
                if(row!= 0 && row-1 >= 0 && visited[row-1][col] == 0 && grid[row-1][col] == '1') {   
                    q.push(make_pair(row-1, col));
                    visited[row-1][col] = 1;
                }
            }
        }
        return 1;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() < 1) {
            return 0;
        }
        int xdim  = grid.size();
        int ydim = grid[0].size();
        vector<vector<int>> visited(xdim, vector<int>(ydim, 0));
        int count{}; 
        
        for(int i = 0; i < xdim; ++i) {
            for(int j = 0; j < ydim; ++j) {
                if(visited[i][j] || grid[i][j] == '0'){
                    continue;
                }
                else {
                    count += bfs(i, j, grid, visited);    
                }
            }
        }
        return count;
    }
};