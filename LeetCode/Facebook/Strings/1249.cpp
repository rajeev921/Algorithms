class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int sz = s.length();
        stack<int> st;
        
        int id{};
        for(int i{}; i < s.length(); ++i){
            if(s[i] =='('){
                st.push(i);
            }
            else if(s[i] ==')') {
                if(!st.empty())
                    st.pop();
                else
                    s[i] ='*';    
            }
        }
        
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};