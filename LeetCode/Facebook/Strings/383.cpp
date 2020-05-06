class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> lookup;
        
        for(char ch : magazine){
            lookup[ch]++;
        }
        
        for(char ch : ransomNote){
            if(lookup.find(ch) == lookup.end() || lookup.at(ch) == 0){
                return false;
            }
            else {
                lookup[ch]--;
            }
        }
        
        return true;
    }
};

// Another Solution
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        auto count = vector<int>(26, 0);
        
        for(char ch : magazine){
            count[ch - 'a']++;
        }
        
        for(char ch : ransomNote){
            if(count[ch - 'a'] == 0){
                return false;
            }
            else {
                count[ch - 'a']--;
            }
        }
        
        return true;
    }
};

// Using Library
