class Solution {
public:
    void reverseStringHelper(vector<char>& s, int start, int end) {
        if(start >= end){
            return;
        }
        swap(s[start], s[end]);
        reverseStringHelper(s, start+1, end-1);
        return;
    }    
    void reverseString(vector<char>& s) {
        if(s.size() < 2) {
            return;
        }
        reverseStringHelper(s, 0, s.size()-1);
    }
};