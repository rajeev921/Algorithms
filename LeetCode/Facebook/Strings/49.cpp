/*
	Input:  ["eat", "tea", "tan", "ate", "nat", "bat"]
	group anagrams
	Output :- 
	[ ["eat", "tea", "ate"], - 3
	  ["tan", "nat"],        - 2
	  ["bat"]                - 1
	]
*/

//TC - O(nlogn), SC - O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz = strs.size();
        vector<vector<string>> res;
        if(sz < 2){
            if(sz==1){
                res.push_back(strs);
                return res;
            }
            return res;
        }
        
        unordered_map<string, vector<string>> lookup;
        
        for(auto s : strs){
            string t = s;
            sort(t.begin(), t.end());
            lookup[t].push_back(s);
        }
        
        for(auto itr=lookup.begin(); itr!= lookup.end(); ++itr) {
            res.push_back(itr->second);
        }
        
        return res;
    }
};

//===============================
// Writing our own counting sort 

string strSort(string& s) { 
    int count[26] = {0}, n = s.length();
    for (int i = 0; i < n; i++)
        count[s[i] - 'a']++;
    int p = 0;
    string t(n, 'a');
    for (int j = 0; j < 26; j++)
        for (int i = 0; i < count[j]; i++)
            t[p++] += j;
    return t;
}
//================================
string sortLowercase(string s) {
    int charExist[26] = {0};
    for (int i{}; i < s.size(); i++) {
        charExist[s[i] - 'a']++;
    }
    string res;
    int j = 0;
    while (j < 26) {
        if (charExist[j] == 0) {
            j++;
        }
        else {
            res.push_back(j + 'a');
            charExist[j]--;
        }
    }
    return res;
}
//================================

//TC - O(n^3), SC - O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz = strs.size();
        vector<vector<string>> res;
        if(sz < 2){
            if(sz==1){
                res.push_back(strs);
                return res;
            }
            return res;
        }
        
        unordered_map<string, string> lookup_str;
        
        for(int i{}; i < strs.size(); ++i){
            lookup_str[strs[i]] = strs[i];
        }    
        
        for(int j{}; j < strs.size(); ++j){
            string src = strs[j];
            if(lookup_str.find(src) != lookup_str.end()) {
                unordered_map<char, int> lookup;
                for(auto ch : src){
                    lookup[ch]++;
                }

                vector<string> t;
                t.push_back(src);
                for(int i=j+1; i < strs.size(); ++i){
                    string temp = strs[i];
                    if(lookup_str.find(temp) != lookup_str.end()) {
                        int k{};
                        for(; k < temp.length(); ++k){
                            if(lookup.find(temp[k])== lookup.end()){
                                break;
                            }
                        }
                        if(k==temp.length()){
                            lookup_str.erase(temp);
                            t.push_back(temp);
                        }
                    }
                }
                if(t.size()!=0)
                    res.push_back(t);    
            }
            
        }
        
        
        return res;
    }
};
