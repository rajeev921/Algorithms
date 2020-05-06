class Solution {
public:
    bool checkValidString(string s) {
        int lower{}, upper{};
        
        for (char c : s) {
            if (c=='(') {
                ++lower;
                ++upper;
            } else if (c==')') {
                --lower; 
                --upper;
            } else { // * encountered
                --lower;
                ++upper;
            }
            lower = max(lower, 0);
            if (upper<0) // unmatched ')' found in the middle of string
                return false;
        }
        
        return lower==0;
    }
};