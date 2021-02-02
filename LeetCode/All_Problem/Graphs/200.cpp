class Solution {
public:
    
    

private:
    vector<pair<int, int>> dir {{0, 1}, {0, -1}, {-1, 0}, {1, 0} };
public:
	// Faster BFS 
	int Bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
			
			queue<pair<int,int>> q;
			q.push(make_pair(row, col));
			visited[row][col] = true;
			
			while(!q.empty()) {
				int sz = q.size();
				for(int i = 0; i < sz; ++i) {
					pair<int, int> p = q.front();
					int row = p.first;
					int col = p.second;
					q.pop();
					if(row+1 != grid.size() && visited[row+1][col] == false && grid[row+1][col] == '1') {   
						q.push(make_pair(row+1, col));
						visited[row+1][col] = true;
					}
					if(col+1 != grid[0].size() && visited[row][col+1] == false && grid[row][col+1] == '1') {
						q.push(make_pair(row, col+1));
						visited[row][col+1] = true;
					}
					if(col != 0 && col-1 >= 0 && visited[row][col-1] == false && grid[row][col-1] == '1') {
						q.push(make_pair(row, col-1));
						visited[row][col-1] = true;
					}
					if(row!= 0 && row-1 >= 0 && visited[row-1][col] == false && grid[row-1][col] == '1') {   
						q.push(make_pair(row-1, col));
						visited[row-1][col] = true;
					}
				}
			}
			return 1;
		}	
public:
	// Slower than the above solution
    int bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col] = true;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto current_point = q.front();
                q.pop();
                for(int j = 0 ; j < dir.size(); ++j) {
                    int nextX = current_point.first + dir[j].first;
                    int nextY = current_point.second + dir[j].second;
                    if(nextX < 0 || nextX==grid.size() || nextY < 0 || nextY==grid[0].size() || grid[nextX][nextY]=='0'  || visited[nextX][nextY]==true) {
                        continue;
                    }
                    q.push({nextX, nextY});
                    visited[nextX][nextY]=true;
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
        vector<vector<bool>> visited(xdim, vector<bool>(ydim, false));
        int count{}; 
        
        for(int i = 0; i < xdim; ++i) {
            for(int j = 0; j < ydim; ++j) {
                if(visited[i][j] || grid[i][j] == '0'){
                    continue;
                } else {   
                    count += bfs(i, j, grid, visited); 
                }
            }
        }
        return count;
    }    
};    
      