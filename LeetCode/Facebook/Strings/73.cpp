//TC - O(n), SC - O(n)
class Solution {
public:
    string simplifyPath(string path) {
        
        string res{""}, tmp{""};
        stringstream ss(path);
        vector<string> vec;
        
        while(getline(ss, tmp, '/')){
            if(tmp == "" || tmp ==".")
                continue;
            /*
            if (tmp == ".." && !vec.empty()) 
                vec.pop_back();
            else if (tmp != "..") 
                vec.push_back(tmp);
            */
            if (tmp != "..")
                vec.push_back(tmp);
            else if (!vec.empty())
                vec.pop_back();    
        }
        
        for(auto str : vec){
            res += '/'+str;
        }
        
        return vec.size()==0 ? "/" : res;
    }
};