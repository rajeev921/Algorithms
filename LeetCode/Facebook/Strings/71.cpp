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


/* Modified Question asked by Facebook  

Given current directory and change directory path ,
return final path

For Example:

    curent                 change            output

    /                    /facebook           /facebook
    /facebook/anin       ../abc/def          /facebook/abc/def
    /facebook/instagram   ../../../../.        /

*/

/*
// Convert string into stream
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string current, string change) {
        
        string res{""}, str{""}, temp{current+"/"+change};

        stringstream ss(temp);
        vector<string> vec;

        while(getline(ss, str, '/')){
            if(str != ".."){
                vec.push_back(str);
                cout << str << "   ";
            }
            else if(!vec.empty())
                vec.pop_back();
        }

        cout << endl;

        for(auto t : vec){
            res += "/" + t;
            cout << res << "   ";
        }
        cout << endl;
        return vec.size()==0 ? "/" : res;
    }
};


int main()
{

    Solution obj;
    string cur{"/facebook/anin"}, change{"../abc/def"};
    cout << obj.simplifyPath(cur, change);
    return 0;
}

*/