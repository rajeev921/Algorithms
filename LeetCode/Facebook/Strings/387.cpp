class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        
        if(len < 2){
            if(len==1){
                return 0;
            }
            return -1;
        }

        unordered_map<char, int> lookup;
        for(auto ch : s){
            ++lookup[ch];
        }

        for(int i{}; i < s.length(); ++i) {
            if(lookup.find(s[i])!= lookup.end() && lookup[s[i]]==1){
                return i;
            }
        }
        
        return -1;
    }
};

// One Pass
class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        
        if(len < 2){
            if(len==1){
                return 0;
            }
            return -1;
        }

        unordered_map<char, pair<int, int>> lookup;
        for(int i{}; i < len; ++i){
            lookup[s[i].first++;
			lookup[s[i].second = i;
        }

        for(auto itr : lookup) {
            if(itr.first == 1){
                return itr.second;
            }
        }
        
        return -1;
    }
};
