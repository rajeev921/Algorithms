class Solution {
public:
    string defangIPaddr(string address) {
        short sz= address.length();
        
        if(sz< 2) {
            if(sz==0){
                return "";
            }
            else if(address[0] =='.'){
                return "[.]";
            }
            return address;
        }
        
        string res;
        for(auto ch : address){
            if(ch =='.'){
                res += '[';
                res += '.';
                res += ']';
            }
            else{
                res += ch;
            }
        }
        
        return res;
    }
};