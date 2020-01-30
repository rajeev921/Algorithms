/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        
        deque <string> q;
        vector<string> mapping {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        q.push_back("");

        for(int i = 0; i<digits.size();i++){
            int x = digits[i]-'0';
            //cout << x <<"  ";
            while(q.front().size()==i) {
                 //cout <<"enter  " << q.front().size() <<"    " << i;
                string t = q.front();
                q.pop_front();
                for(char s : mapping[x]) {
                    cout << t+s << "   ";
                    q.push_back(t+s);
                }
             }
            cout <<endl;
            }

       vector<string> ans(q.begin(), q.end());
       return ans;
    }
};