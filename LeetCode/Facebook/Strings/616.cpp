class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> mp(n, 0);
        
        for(string sd : dict) {   // O(n*m)
            int m = sd.size(), p = -1;
            while (true) {
                p = s.find(sd, p+1);
                if(p == string::npos)
                    break;
                for (int j{p}; j < p+m; ++j) 
                    mp[j] = 1;
            } 
        }
        
        string ans;
        
        for (int i = 0; i < n;) {
            if (mp[i]) {
                ans += "<b>";
                while (i < n && mp[i]) 
                    ans += s[i++];
                ans += "</b>";
            }
            else {
                while (i < n && mp[i] == 0) 
                    ans += s[i++];
            }
        }

        return ans;
    }
};