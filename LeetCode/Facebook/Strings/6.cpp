class Solution {
public:
    string convert(string s, int numRows) {
        int sz = s.length();
        if(sz==0 || numRows==0){
            return s;
        }
        
        vector<vector<char>> pat(numRows, vector<char>(sz, '0'));
        int i{}, col{};
        cout << numRows <<"  "<< sz << endl;
        
        while( col < pat[0].size() && i < s.size()) {
            int row{};
            for(; row < numRows; ++row) {
                pat[row][col] = s[i];
                ++i;
            }
            col++;
            --row;
            // Diagonal back into row
            while(--row > 0 && i < s.size()){
                pat[row][col] = s[i];
                ++col;
                ++i;
            }
        }
        
        string res;
        for(int row = 0; row < numRows; ++row) {
            for(int col = 0; col < pat[0].size(); ++col){
                if(pat[row][col] != '0'){
                   res += pat[row] [col];
                }
            }
        }
        
        return res;
    }
};
/*
PAYPALISHIRING, 3
Output: "PAHNAPLSIIGYIR"
                    P   A   H   N   0
                    A P L S I I G   1
                    Y   I   R       2
 0 1 2 3 4 5 6 7 8 9 10 11 12 13                    
"P A Y P A L I S H I  R I  N  G", numRows = 4
Output: "PINALSIGYAHRPI"  PIN
Explanation:
                    P     I    N
                    A   L S  I G
                    Y A   H R
                    P     I
*/