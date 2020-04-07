class Solution {
private:	
	bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
		if (colors[node]){
			return colors[node]==color;
		}
        
        colors[node]=color;
        for(int neigh : graph[node]) {
            cout << node << "   " << neigh <<endl;
        	if(!dfs(graph, colors, neigh, -color))
        		return false;
        }

		return true;
	}
public:
	bool isBipartite(vector<vector<int>>& graph) {

		int m, color{};
        m = graph.size();
		vector<int> colors(m, 0);
        
		for(int i{}; i < graph.size(); ++i){
			if(!colors[i] && !dfs(graph, colors, i, 1)){
				return false;       
			}
		}

		return true;
    }	
};
