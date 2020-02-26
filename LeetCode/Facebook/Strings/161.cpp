/* 		One edit distance
Given two strings s and t, determine if they are both one edit distance apart.

Note: 
There are 3 possiblities to satisify one edit distance apart:
Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t

Example 1:
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Example 2:
Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.

Example 3:
Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

*/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(abs(len1-len2) > 1 || s.compare(t)==0) 
            return false;
        
        int i{}, j{};
        bool found{false};
        
        while(i < len1 and j < len2){
            if(s.at(i) != t.at(j)){
                if(found)
                    return false;
                found = true;
                if(len1 < len2)
                    --i;
                else if(len1 > len2)
                    --j;
            }   
            ++i;
            ++j;
        }
			
        return true;
    }
};
/*
string is empty
can be 1 
alphanumeric
single string will fail
comparison between lower and upper alphabet pass
*/







