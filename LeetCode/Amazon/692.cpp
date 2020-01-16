class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> lookup;
        for(auto word : words) {
            lookup[word]++;
        }
        
        auto cmp= [&](pair<string, int> p1, pair<string, int> p2){
            return (p1.second < p2.second ||(p1.second==p2.second && p1.first > p2.first));
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for(auto itr = lookup.begin(); itr != lookup.end(); ++itr) {
            pq.push(make_pair(itr->first, itr->second));
        }
        
        vector<string> res;
        for(int i=0; i<k; i++)
        {
          res.push_back(pq.top().first);
          pq.pop();  
        }
        return res;
    }
};