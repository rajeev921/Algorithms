class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) {
            map[c]++;  
        }
        int counter=t.size(), d=INT_MAX;
        int begin{}, end{}, head{};
        
        while(end<s.size()) {
            if(map[s[end++]]-- >0) 
                counter--; //in t
            while(counter==0) { //valid
                if(end-begin<d)  
                    d=end-(head=begin);
                if(map[s[begin++]]++==0) 
                    counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};