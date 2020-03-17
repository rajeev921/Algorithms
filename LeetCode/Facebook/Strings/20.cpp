class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(char& ch : s)
        {
            if(st.empty())
            {
                st.push(ch);
            }
            else
            {
                if(ch == '[' || ch == '{' || ch == '(')
                {
                    st.push(ch);
                }
                else
                {
                    char temp = st.top();
                    if(temp == '[' && ch ==']')
                    {
                        st.pop();
                    }
                    else if(temp == '{' && ch =='}')
                    {
                        st.pop();
                    }
                    else if(temp == '(' && ch ==')')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(ch);
                    }
                }
            }
        }
        
        if(st.size() > 0)
        { 
            return false;
        }
        else
        {
            return true;
        }
    }
};