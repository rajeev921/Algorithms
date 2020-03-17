class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) {
            return "";
        }
        else if(strs.size()==1) {
            return strs[0];
        }
        
        return longestCommonPrefix(strs, 0, strs.size()-1);
    }
    string longestCommonPrefix(vector<string>&str, int start, int end) {
        if(start== end) {
            return str[start];
        }
        int mid = start + (end-start)/2;
        string leftStr = longestCommonPrefix(str, start, mid);
        string rightStr = longestCommonPrefix(str, mid+1, end);
        return commonPrefix(leftStr, rightStr);
    }
    
    string commonPrefix(string left, string right) {
        int minLength = min(left.length(), right.length());
        
        for(int i{}; i < minLength; ++i){
            if(left[i] != right[i]) {
                return left.substr(0, i);
            }
        }
        
        return left.substr(0, minLength);
    }
};

// Another solution

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        short sz = strs.size();
        if(sz < 2) {
            if(sz==1) {
                return strs[0];    
            }
            return "";
        }

        int min_len=INT_MAX;
        for(auto str : strs) {
            if(str.empty())
                return "";
            int cur_len = str.size();
            min_len = min(min_len, cur_len);
        }
        
        string res ="";
        for(int i{}; i < min_len; ++i) {
            for(int j = 1; j < sz; ++j) {
                if(strs[j][i] == 0)
                    return res; 
                if(strs[0][i] != strs[j][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }
        
        return res;
    }
};

// Another Solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], idx++)
            for(int i=0; i<strs.size(); i++)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[i-1][idx]))
                    return prefix;
        return prefix;
    }
};

