class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for(string word : words){
            map[word]++;
        }
        
        auto comp = [&](const pair<string,int>& a , const pair<string,int>& b){
            return a.second < b.second || (a.second == b.second && a.first > b.first); 
        };

        vector<string> res;
        priority_queue<pair<string, int>, vector<pair<string, int32_t>>, decltype(comp)> pq(comp);
        for(auto it = map.begin(); it != map.end(); it++){
            //cout<< it->first << "->" << it->second <<endl;
            pq.push(make_pair(it->first, it->second));
        }
        
        for(int i=0; i<k; i++)
        {
          res.push_back(pq.top().first);
          pq.pop();  
        }
        return res;
    }
};