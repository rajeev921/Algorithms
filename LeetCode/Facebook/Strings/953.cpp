/*
Explanation
Build a transform mapping from order,
Find all alien words with letters in normal order.

For example, if we have order = "xyz..."
We can map the word "xyz" to "abc" or "123"

Then we check if all words are in sorted order.

Complexity
Time O(NS)
Space O(1)

*/
class Solution {
public:
    bool isAlienSorted(vector<string> words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        
        for(int i{}; i < order.length(); ++i) {
            map[order[i]-'a'] = i;
        }
        
        for (int i = 1; i < words.size(); i++)
            if (bigger(words[i - 1], words[i]))
                return false;
        return true;
    }

    bool bigger(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        for (int i = 0; i < n && i < m; ++i)
            if (s1.at(i) != s2.at(i))
                return map[s1.at(i) - 'a'] > map[s2.at(i) - 'a'];
        return n > m;
    }
private:
    size_t map[26]{};
};