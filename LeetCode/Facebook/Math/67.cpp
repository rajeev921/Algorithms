/*
Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/
class Solution {
public:
    string addBinary(string a, string b) {
        
        int len1 = a.length();
        int len2 = b.length();
        int i = len1-1, j = len2-1, sum{};
        
        string res;
        
        while( i >=0 || j >= 0|| sum==1){
            sum += (i >= 0) ? a[i--]-'0' : 0;
            sum += (j >= 0) ? b[j--]-'0' : 0;
            res += char(sum%2+'0') ;
            sum=sum>>1;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};