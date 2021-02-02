
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cout << "if push i '(' " << i <<endl ;
                stk.push(i);
            } else {
                stk.pop();
                cout << "else pop i ')' " << i <<endl;
                if (stk.empty()) {
                    cout << "stack is empty  push " << i <<endl;
                    stk.push(i);
                } else {
                    ans = max(ans, i - stk.top());
                    cout << "stack is not empty ans i top" << ans << i << stk.top() <<endl;
                }
            }
        }
        return ans;
    }
};
/*
Instead of finding every possible string and checking its validity, we can make use of stack while scanning the given string to check if the string scanned so far is valid, and also the length of the longest valid string. In order to do so, we start by pushing -1−1 onto the stack.
For every \text{‘(’}‘(’ encountered, we push its index onto the stack.
For every \text{‘)’}‘)’ encountered, we pop the topmost element and subtract the current element's index from the top element of the stack, which gives the length of the currently encountered valid string of parentheses. If while popping the element, the stack becomes empty, we push the current element's index onto the stack. In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.
*/

// Dp
class Solution {
public :
    int longestValidParentheses(string s) {
        int sz = s.length();
        if(sz < 2){
            return 0;
        }
        vector<int> V(sz, 0);
        int open{};
        int max{};
        
        for (int i=0; i<sz; i++) {
            if (s[i] == '(') open++;
            if (s[i] == ')' && open > 0) {
                // matches found
                V[i] = 2+ V[i-1];
                // add matches from previous
                if(i-V[i]>0)
                    V[i] += V[i-V[i]];
                open--;
            }
            if (V[i] > max) max = V[i];
        }
        return max;
    }
    
};
