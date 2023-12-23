class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.length();
        if(len < 2){
            if(len==0){
                return false;
            }
            return true;
        }
        
        int i{-1};
        while(++i < --len){
            if(s[i] != s[len]){
                return palindrome(s, i+1, len) || palindrome(s, i, len-1);
            }
        }
        
        return true;
    }
    
    bool palindrome(string s, int i, int len) {
        
        while(i < len){
            if(s[i] != s[len]){
                return false;
            }
            ++i;
            --len;
        }
        
        return true;
    }
};