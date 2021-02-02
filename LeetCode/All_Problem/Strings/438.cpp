class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // generate all anagram and find in the current string if it is present 
        // save the starting position in the vector
        
        int len1 = s.length(), len2 = p.length();
        
        if((len1 == 0 || len2 == 0) ||(len2 > len1))
            return {};
        
        vector<int> res;
        unordered_map<char, int>lookup;
        
        for(auto ch : p){
            ++lookup[ch];
        }
        
        int start{}, end{}, counter{len2};
        
        while(end < len1){
            char ch1 = s.at(end);
            if(lookup.find(ch1) != lookup.end() && lookup[ch1] >0)
                --counter;
            lookup[s.at(end)]--;
            ++end;
            while(counter == 0){
                if((end-start) == len2)
                    res.push_back(start); 
                char ch2 = s.at(start);
                if(lookup.find(ch2) != lookup.end()){
                    lookup[ch2]++;
                    if(lookup[ch2] > 0)
                        ++counter;    
                }
                ++start;
            }
        }
        return res;    
    }
};

// Better Solution - TC O(n), SC O(n)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // generate all anagram and find in the current string if it is present 
        // save the starting position in the vector
        
        int len1 = s.length(), len2 = p.length();
        
        if((len1 == 0 || len2 == 0) ||(len2 > len1))
            return {};
        
        vector<int> res;
        unordered_map<char, int>lookup;
        
        for(auto ch : p){
            ++lookup[ch];
        }
        
        int start{}, end{}, counter{len2};
        
        while(end < len1){
            char ch1 = s.at(end);
            if(lookup.find(ch1) != lookup.end() && lookup.at(ch1) > 0)
                --counter;
            lookup[ch1]--;
            
            // if the window size equals to p
            if((end-start) == len2-1){
                // check counters to 0 add it to the list
                if(counter == 0)
                    res.push_back(start); // add the left index
                
                // move start pointer to start new search
                char ch2 = s.at(start);
                if(lookup.find(ch2) != lookup.end() && lookup.at(ch2) >= 0){
                    ++counter;    
                }
                lookup.at(ch2)++;
                ++start;
            }
            ++end;
        }
        return res;    
    }
};