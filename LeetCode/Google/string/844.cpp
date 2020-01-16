class Solution {
public: 
    stack<char> stringOperation(string S) {
        stack<char> st;
        
        for(auto ch : S) {
            if(ch == '#' && !st.empty()) {
                //cout << st.top() << "  ";
                st.pop();
            }
            else if(ch != '#'){
                st.push(ch);
            }
        }
        return st;
    }
    
public:
    bool backspaceCompare(string S, string T) {
        if(S.empty() && T.empty()) {
            return true;
        }
        else if(S.empty() || T.empty()) {
            return false;
        }
        
        stack<char> st_first = stringOperation(S);
        stack<char> st_second = stringOperation(T);
        
        cout <<endl << st_first.size() <<st_second.size() ;
        
        while(!st_first.empty() && !st_second.empty()) {
            if(st_first.top() != st_second.top()) {
                return false;
            }
            st_first.pop();
            st_second.pop();
        }
        if(st_first.size() > 0 || st_second.size() > 0) {
            return false;
        }
        
        return true;
    }
};

// Another Solution 2
class Solution {
public: 
    string clearString(string S) {
        int firstP{}, secondP{};
        
        while(firstP < S.length()) {
            if(S[firstP] == '#') {
                if(secondP > 0){
                    --secondP;
                }    
            } else{
                S[secondP++] = S[firstP];
            }
            ++firstP;
        }
        
        return S.substr(0, secondP);
    }
    
public:
    bool backspaceCompare(string S, string T) {
        if(S.empty() && T.empty()) {
            return true;
        }
        else if(S.empty() || T.empty()) {
            return false;
        }
        
        return (!clearString(S).compare(clearString(T)));
    }
};
