class Solution {
public:
    string licenseKeyFormatting(string S, int K) { 
       string temp;
        int i{};
        for(; i < S.length(); i++) {
            if (S[i]=='-') continue;
             temp+=toupper(S[i]);
        }
        
        string temp2; 
        int track{};
        
        for(i = temp.length()-1; i>=0; --i) {
            track++;
            temp2+=temp[i];
            if (track==K && i != 0 ) {
                temp2+="-";
                track = 0;
            }
        }
        reverse(temp2.begin(),temp2.end());
        return temp2;
    }
};