class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> lookup;
        
        for(int i{}; i < nums.size(); ++i) {
            lookup[nums[i]]++;
        }
        
        auto cmp = [&](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second || (a.second==b.second && a.first > b.first);
        };
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        for(auto it=lookup.begin(); it != lookup.end(); ++it) {
            pq.push(make_pair(it->first, it->second));    
        }
        
        vector<int> res;
        for(int i=1; i <= k; ++i) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};