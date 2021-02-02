/*
Longest Substring with At Most K Distinct Characters
Solution
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
*/


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.length();
        if(k == 0)
            return 0;
        if(len < 2)
            return len;
        
        unordered_map<char, int> lookup;
        int left{}, right{}, counter{}, maxLen{INT_MIN};
        
        while(right < len){
            char ch1 = s.at(right);
            ++lookup[ch1];
            if(lookup[ch1]==1)
                ++counter;
            ++right;
            while(counter > k){
                char ch2 = s.at(left);
                --lookup[ch2];
                if(lookup[ch2]==0)
                    --counter;
                ++left;
            }
            maxLen = max(maxLen, right-left);
        }
        
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        unordered_map<char,int> count; //Char,Count
        int l=0,distinct=0,res=0;
        
        // l is the leftmost starting of substring, r is the rightmost
        for (int r = 0; r < s.size(); r++) 
        {
            //If character not seen before
            if (count[s[r]] == 0) 
                distinct++;
              
            //Increment count of the char
             count[s[r]]++;
            
            //If there are more distinct char
            //Start removing from left until Distict Chars == k
            while(distinct > k) 
            {
                count[s[l]]--;
                if(count[s[l]]==0) 
                    distinct--;
                l++;
            }   
            res = max(res, r - l + 1);
        }

        return res;
    }
};


// Another Solution 
class Solution {
public:
    int longestSubstringKDistinct(string& str, int k){
        vector<char> lookup(256, ' '); // 0 to 255 
        string res{""};
        
        for(auto ch : str){
            if(lookup[ch] == ' ' && k > 0){
                lookup[ch] = ch;
                res += ch;
                --k;
            }
            else if(lookup[ch] != ' ')
                res += ch;
            else
                break;
        }
        cout << res<< endl;
        return res.length();
    }
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.length();
        if(len == 0 || k == 0)
            return 0;
        
        int min_len{INT_MIN};
        
        for(int i{}; i < len; ++i){
            string str = s.substr(i, len);
            int len = longestSubstringKDistinct(str, k);
            if(len > min_len)
                min_len = len;
        }
        
        return min_len;
    }
};

