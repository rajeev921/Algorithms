class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;
        int indexS = 0, indexT = 0, cnt =0;
        while (indexT < t.length()) {
            if (t.at(indexT) == s.at(indexS)) {
                indexS++;
                if (indexS == s.length()) return true;
            }
            indexT++;
        }
        return false;
    }
};