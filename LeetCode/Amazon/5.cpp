// Brute_force
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
        if(s.size() == 0 || s.size() == 1) return true;
        int i(0), j(s.size() - 1);
        while(s[i] == s[j] && i < j) i++, j--;
        return i >= j;
    }
};

// Optimal Solution  --- using DP
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res{null};
        int palindromeStartsAt{}, maxLen{};
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        // dp[i][j] indicates whether substring s starting at index i and ending at j is palindrome
        
        for (int i = n - 1; i >= 0; i--) { // keep increasing the possible palindrome string
            for (int j = i; j < n; j++) {  // find the max palindrome within this window of (i,j)
                
                //check if substring between (i,j) is palindrome
                dp[i][j] = s.at(i) == s.at(j) // chars at i and j should match
                && (j - i < 3 // if window is less than or equal to 3, just end chars should match --- see below for more
                || dp[i + 1][j - 1]); // if window is > 3, substring (i+1, j-1) should be palindrome too
                
                //update max palindrome string
                if (dp[i][j] && (res == null || j - i + 1 > res.length())) {
                    palindromeStartsAt = i;
                    maxLen = j-i+1;
                }
            }
        }
        return s.substr(palindromeStartsAt, palindromeStartsAt+maxLen);
    }
};

/*
It is just exclude the condition dp[i + 1][j - 1] when i and j are within 2 index distance. In short,
if i == j, dp[i][j] = s.charAt(i) == s.charAt(j)
i + 1 == j, dp[i][j] = s.charAt(i) == s.charAt(j)
i + 2 ==j , dp[i][j] = s.charAt(i) == s.charAt(j) and since the middle one doesn't matter.
Only when i + 3 == j, dp[i][j] = s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1];

*/

/*
"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"

*/