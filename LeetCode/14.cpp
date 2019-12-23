class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1) 
                return strs[0];
                
        string input = strs[0];
        int idx = 0;
        string prefix{};
        bool checker = false;
        
        for(char& c : input) {
            for(int i = 1; i < strs.size(); ++i)
            {
               string temp = strs[i];
               if(c != temp.at(idx))
               {
                   checker = true;
                   break;
               }
            }
            if(checker == false)
            {
               //prefix += c;
                prefix.push_back(c);
                ++idx;
            }
            else
            {
                break;
            }
        }
        
        return prefix;
    }
};


class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
          if(strs.size() == 0)
          {
              return "";
          }
          else
          {
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