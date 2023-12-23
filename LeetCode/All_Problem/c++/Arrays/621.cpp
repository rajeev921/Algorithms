class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char, int> lookup;
        int count{};
        
        for(auto ch : tasks){
            lookup[ch]++;
            count = max(count, lookup[ch]);
        }
        
        int res = (n+1)*(count-1);
        
        for(auto e : lookup) 
            if(e.second == count) res++;
        return max((int)tasks.size(), res);
    }
};