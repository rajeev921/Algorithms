class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 1) {
            return (cost[0]);
        }
        else if(cost.size() == 2) {
            return (min(cost[0], cost[1]));
        }
        
        int n = cost.size();
        vector<int> minCost(n, -1);
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        for(int i = 2; i < n; ++i) {
            minCost[i] = cost[i] + min(minCost[i-1], minCost[i-2]);
        }
        
        return (min(minCost[n-1], minCost[n-2]));
    }
};