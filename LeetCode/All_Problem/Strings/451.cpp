class Solution {
public:
    string frequencySort(string s) {
        int len = s.length();
        if(len < 3) {
            return s;
        }
        
        unordered_map<char, int> lookup;
        for(auto ch : s) {
            ++lookup[ch];            
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto itr=lookup.begin(); itr != lookup.end(); ++itr) {
            pq.push({itr->second, itr->first});
        }
        
        string res;
        while(!pq.empty()) {
            auto tp = pq.top();
            for(int i{}; i < tp.first; ++i){
                res += tp.second;
            }
            pq.pop();
        }
        
        return res;
    }
};

/*
tree - eert, eetr
cccaaa - aaaccc, cccaaa
Aabb - bbaA, bbAa
*/