#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::string limitKCharactersPerEntry(const std::string& str, int limit)
    {
        int sz = str.length();
        if(limit > sz)
            return str;

        if(limit == sz && str[limit-1] != ' ')
            return str;

        std::string res;
        int spaceIndex = 0;

        for(int i = 0; i < str.size(); ++i) {
            if (str[limit] == ' ') 
                spaceIndex = limit;
            
            if(i < limit) {
                if(str[i] == ' ') {
                    spaceIndex = i;
                }
            } else break;
        }

        res = str.substr(0, spaceIndex);

        return res;
    }
};

int main()
{
    vector<string> strs{"codility We test coders",
                        " co de my",
                        " co de my",
                        "   ",
                        "   re", 
                        " c ",
                        " c d  ", 
                        "co de my", 
                        "Word", 
                        "codility We test coders",
                        "withOutSpaces", 
                        "", 
                        "Separatedby hyphens", 
                        "      Codility We test coders     ",
                        "      Codility We test coders     ",
                        "withOutSpaces"
                        };

    vector<int> limits{14, 5, 7, 2, 2, 3, 5, 5, 4, 23, 14, 14, 14, 14, 10, 7};

    Solution obj = Solution();
    
    for(int i{}; i < strs.size(); ++i){
        cout << obj.limitKCharactersPerEntry(strs[i], limits[i]) << endl;
    }
    /*
    cout << obj.limitKCharactersPerEntry(strs[8], limits[8]) << endl;
    cout << obj.limitKCharactersPerEntry(strs[9], limits[9]) << endl;
    cout << obj.limitKCharactersPerEntry(strs[10], limits[10]) << endl;
    */
    return 0;
}