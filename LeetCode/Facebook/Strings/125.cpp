class Solution {
public:
    bool isPalindrome(string s) {
       int len = s.length();
       
        if(len==0 || len==1){
            return true;
        }
        
        int i{}, j{len-1};
        
        while(i < j) {
            if(!isalnum(s[i])){
                ++i;
                continue;
            }
            if(!isalnum(s[j])){
                --j;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            ++i;
            --j;
        }
        
        return true;
    }
};