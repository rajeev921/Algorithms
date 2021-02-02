// Palindrome, DP, String Manipulationclass Solution {

// Expensive Algo - O(n3)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int max_len{};
        string str;
        
        for(int i= 0; i < len+max_len; ++i) {
            for(int j =len-1; j >=i+max_len; --j) {
                if(s[j] != s[i])
                    continue;
                string cur_str = s.substr(i, j - i + 1);
                if(isPalindrome(cur_str) && cur_str.size() > max_len) {
                    str = cur_str;
                    max_len = cur_str.size();
                }
            }
        }
        return str;
    }
    
    bool isPalindrome(string s){
        if(s.size() == 0 || s.size() == 1) 
			return true;
        int i(0), j(s.size() - 1);
        while(s[i] == s[j] && i < j) i++, j--;
        return i >= j;
    }
};

// P(i, j) = { true,  if the substring Si,...Sj is a palindrome
//			 { false, otherwise
// P(i, j) = (P(i+1, j+1) and Si==Sj)
// Base Case are - P(i, i) = true, P(i, i+1) = (Si==Si+1)
// Time Complexity - O(n2), Space Complexity - O(1)


class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        if(sz < 2)
			return s;
        int start{}, end{};
        for (int i = 0; i < sz-1; i++) {
            int len1 = extendPalindrome(s, i, i, start);  //assume odd length, try to extend Palindrome as possible
            int len2 = extendPalindrome(s, i, i+1, start); //assume even length.
            int len = max(len1, len2);
            if(len > end-start) {
                start = i - ((len - 1) / 2);
                end = i + (len/2);
            }
        }
        return s.substr(start, end);
    }
private:
	int extendPalindrome(string s, int left, int right, int &start) {
        if(s.empty() || left > right){
            return 0;
        }
        while (left >= 0 && right < s.size() && s.at(left)==s.at(right)) {
            --left;
            ++right;
        }
        return right-left-1;
    }
};

//babad - bab, aba

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) 
            return "";
        if (s.size() == 1) 
            return s;
        
        int min_start = 0, max_len = 1;
        
        for (int i = 0; i < s.size();) {
			if (s.size() - i <= max_len / 2) 
				  break;
			int j = i, k = i;
			while (k < s.size()-1 && s[k+1] == s[k]) 
				++k; // Skip duplicate characters.
				i = k+1;
			while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { 
				++k; --j; 
			} // Expand.
			int new_len = k - j + 1;
			if (new_len > max_len) { 
				min_start = j; max_len = new_len; 
			}
        }
        return s.substr(min_start, max_len);
    } 
};
