class Solution {
public:
    // bucket sort TC - O(N*M), SC - O(N*M)
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        
        vector<vector<pair<int, int>>> buckets(2001);
        int n = workers.size(), m = bikes.size();
        int min_b{INT_MAX}, max_b{INT_MIN};
        
        for(int i{}; i < n; i++){
            for(int j{}; j < m; ++j){
                int distance = (abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]));
                max_b  = max(distance, max_b); 
                min_b = min(distance, min_b);
                buckets[distance].push_back({i, j});
                //q.push({distance,{i,j}});
            }
        }
        
        vector<int> res(n, -1);
        vector<bool> bikeUsed(m, false);
        
        for (int d = min_b; d <= max_b; d++) {
            for (int k = 0; k < buckets[d].size(); k++) {
                if (res[buckets[d][k].first] == -1 && !bikeUsed[buckets[d][k].second]) {
                    bikeUsed[buckets[d][k].second] = true;
                    res[buckets[d][k].first] = buckets[d][k].second;
                }    
            }
        }
        
        return res;
    }
};