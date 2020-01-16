class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        if(sz < 2) {
            return;
        }
        int last = sz-1;
        int first{};
        
        while(first < last) {
            swap(s[first], s[last]);
            ++first;
            --last;
        }
        
        return;
    }
};