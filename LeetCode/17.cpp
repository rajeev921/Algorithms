
class Solution {
public:
    
    void letterCombinations(string digits, string& combination, int idx, std::unordered_map<char, string>& num_to_char, vector<string>& result)
    {
        if(idx == digits.length()) {
            result.push_back(combination);
            return;
        }
        
        
        
    }
    vector<string> letterCombinations(string digits) 
    {        
        if(digits.empty()) return {};
        
        std::unordered_map<char, string> num_to_char {{'2', "abc"}, {'3', "def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"} }; 
        
        vector<string> result;
        string combination(digits.length(), ' ');
        letterCombinations(digits, combination, 0, num_to_char, result);
                
        return result;
    }
};