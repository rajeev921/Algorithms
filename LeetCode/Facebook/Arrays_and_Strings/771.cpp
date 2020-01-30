class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.length()==0 && S.length()==0){
            return 0;
        }
        
        int out{};
        unordered_map<char, char> lookup;
        
        for(int i =0; i < J.length(); ++i) {
            if(lookup.find(J[i])==lookup.end()) {
                lookup[J[i]] = J[i];
            }    
        }
        for(int i =0; i < S.length(); ++i) {
            if(lookup.find(S[i])!=lookup.end()) {
                ++out;
            }    
        }
        
        return out;
    }
};

// Another solution 
class Solution2 {
public:
    int numJewelsInStones(string J, string S) {
        if(J.length()==0 && S.length()==0){
            return 0;
        }
        
        int out{};
        char lookup[128] {};
  
        for(int i =0; i < J.length(); ++i) {
            lookup[J[i]] = 1;
        }
        
        for(int i =0; i < S.length(); ++i) {
            if(lookup[S[i]]==1) {
                ++out;
            }    
        }
        
        return out;
    }
};