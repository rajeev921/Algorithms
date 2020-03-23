/*  
Minimum Window Substring 

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
A, AD, ADO, ADOB, ADOBE, ADOBEC, ADOBECO, ADOBECOD, ADOBECODE, ADOBECODEB, ADOBECODEBA, ADOBECODEBAN, ADOBECODEBANC

	D, DO, DOB, DOBE, DOBEC, DOBECO, DOBECOD, DOBECODE, DOBECODEB, DOBECODEBA, DOBECODEBAN, DOBECODEBANC

		O, OB, OBE, OBEC, OBECO, OBECOD, OBECODE, OBECODEB, OBECODEBA, OBECODEBAN, OBECODEBANC

			B, BE, BEC, BECO, BECOD, BECODE, BECODEB, BECODEBA, BECODEBAN, BECODEBANC

				E, EC, ECO, ECOD, ECODE, ECODEB, ECODEBA, ECODEBAN, ECODEBANC

					C, CO, COD, CODE, CODEB, CODEBA, CODEBAN, CODEBANC

						O, OD, ODE, ODEB, ODEBA, ODEBAN, ODEBANC

							O, OD, ODE, ODEB, ODEBA, ODEBAN, ODEBANC

								D, DE, DEB, DEBA, DEBAN, DEBANC

									E, EB, EBA, EBAN, EBANC

										B, BA, BAN, BANC

											B, BA, BAN, BANC

*/

// Time Complexity -O(n^2), Space Complexity - O(n)
// It will be TLE for very long string.
class Solution {
public:
    // find the substring in the given string
    int compare_substr(const string &s, const string& t) {
        unordered_map<char, int> lookup;
        for(int i{}; i < t.size(); ++i) {
            ++lookup[t[i]];
        }
        int count{}, i{};
        for( ; i < s.size(); ++i) {
            if(lookup.find(s[i])!= lookup.end() && lookup.at(s[i])!=0) {
                --lookup[s[i]];
                ++count;
            }
            if(count==t.size()) {
                return i+1;
            }
        }
        if(count==t.size()) {
            return i+1;
        }
        return -1;
    }
    string minWindow(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        string res{""};
        
        if(s_len==0 || t_len==0) {
            return "";
        }
		
        int small_len{INT_MAX};
        for(int i{}; i < s_len; ++i) {
            string str = s.substr(i, s_len);
            int cur_len = compare_substr(str, t);
            if(cur_len !=-1 && cur_len < small_len) {
                res = s.substr(i, cur_len);
                small_len = cur_len;
            }
        }

      return res;
    }
};

//=============================================
// Time Complexity -O(n), Space Complexity - O(n)
// Time Complexity -O(n), Space Complexity - O(n)
class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        string res{""};
        
        if(s_len==0 || t_len==0) {
            return res;
        }
        
        vector<int> hist(128, 0);
        for(char ch : t) //  
            ++hist[ch];
        
        int remaining = t.length();
        int left{}, right{}, minStart{}, minLen{INT_MAX};
        
        while(right < s.length()) {
            if(--hist[s[right++]] >= 0)
                remaining--;
            while(remaining == 0){
                if(right - left < minLen){ 
                    minLen = right - left;
                    minStart = left;
                }
                if(++hist[s[left++]] > 0)
                    ++remaining;
            }
        }
        
        return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
    }
};

// Time Complexity -O(n), Space Complexity - O(n)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        // Statistic for count of char in t
        for (auto c : t) 
            m[c]++;
        
        // t_size represents the number of chars of t to be found in s.
        int start{}, end{}, minStart{}, minLen{INT_MAX};
        size_t s_size = s.size(), t_size = t.size();

        // Move end to find a valid window.
        while (end < s_size) {
            // If char in s exists in t, decrease t_size
            if (m[s[end]] > 0)
                t_size--;
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            m[s[end]]--;
            end++;
            // When we found a valid window, move start to find smaller window.
            while (t_size == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                m[s[start]]++;
                // When char exists in t, increase t_size.
                if (m[s[start]] > 0)
                    t_size++;
                start++;
            }
        }
        
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        
        return "";
    }
};