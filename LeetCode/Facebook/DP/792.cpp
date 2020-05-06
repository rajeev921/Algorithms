/*
Input: S = "abcde" words = ["a", "bb", "acd", "ace"]
Output: 3
*/
// Runtime is 180ms
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<pair<int, int>> waiting[128];
        
        for (int i = 0; i < words.size(); i++) {
            waiting[words[i][0]].emplace_back(i, 1);
        }
            
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance)
                waiting[words[it.first][it.second++]].push_back(it);
        }
        return waiting[0].size();
    }
};

// Runtime is 204ms
class Solution {
public:
  int numMatchingSubseq(const string& S, vector<string>& words) {
    vector<vector<int>> pos(128);    
    for (int i = 0; i < S.length(); ++i)
      pos[S[i]].push_back(i);
    int ans = 0;
    for (const string& word : words)
      ans += isMatch(word, pos);
    return ans;
  }
  
private:
  unordered_map<string, bool> m_;
  bool isMatch(const string& word, const vector<vector<int>>& pos) {
    if (m_.count(word)) return m_[word];       
    int last_index = -1;
    for (const char c : word) {
      const vector<int>& p = pos[c];
      const auto it = std::lower_bound(p.begin(), p.end(), last_index + 1);      
      if (it == p.end()) return m_[word] = false;
      last_index = *it;      
    }
    return m_[word] = true;
  }
};