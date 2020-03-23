class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> stck;
        vector<int> res(n);
        
        string prev;
        for(string str : logs){
            // parse string
            istringstream iss(str);
            int id, time;
            string status;
            
            getline(iss, str,':');
            id = stoi(str);
            getline(iss, str,':');
            status = str;
            cout << status;
            getline(iss, str,':');
            time = stoi(str);
            
            if(status=="start"){
                if(!stck.empty())
                    res[stck.top().first] += time-stck.top().second;
                stck.push({id, time});
            }else {
                auto cur = stck.top();
                stck.pop();
                
                res[cur.first] += time-curr.second+1;
                if(!stck.empty())
                    stck.top().second = time+1;
            }
        }
            
        return res;
    }
};

TC - O(n)
SC - O(n)
