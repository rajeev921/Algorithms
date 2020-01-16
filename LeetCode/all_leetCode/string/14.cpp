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

class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
          if(strs.size() == 0){
              return "";
          }
          else{
              return longestCommonPrefix(strs, 0, strs.size()-1);
          }
    }
    string longestCommonPrefix(vector<string>& strs, int start, int end)
    {
          if( start == end) 
          {
              return strs[start];
          }
          else  
          {
              int mid = (start+end)/2;
              string lcpLeft = longestCommonPrefix(strs, start, mid);
              string lcpRight = longestCommonPrefix(strs, mid+1, end);
              return commonPrefix(lcpLeft, lcpRight);
          }
    }
    string commonPrefix(string left, string right)
    {
          int min_ = std::min(left.length(), right.length());
          for(int i = 0; i < min_; ++i) 
          {
              if(left.at(i) != right.at(i))
              {
                  return left.substr(0, i);
              }
          }
          return left.substr(0, min_);
  }
};