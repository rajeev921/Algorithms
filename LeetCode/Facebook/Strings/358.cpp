class Solution {
public:
    string rearrangeString(string s, int k) {
        int len = s.length();
        if(len <2 || k < 2){
            if(len==1 || k < 2){
                return s;
            }
            return "";
        }
        
        unordered_map<char, int> lookup;
        for(auto ch : s) lookup[ch]++;
        
        priority_queue<pair<int, char>> pq;
        for(auto itr=lookup.begin(); itr != lookup.end(); ++itr){
            pq.push({itr->second, itr->first});
        }
        
        string res;
        while(!pq.empty()){
            vector<pair<int, char>> cache;
            int count = min(k, len);
            for(int i{}; i< count; ++i){
                if(pq.empty())
                    return "";
                auto t = pq.top();
                pq.pop();
                res += t.second;
                if(--t.first > 0)
                    cache.push_back(t);
                len--;
            }
            for(auto v : cache)
                pq.push(v);
        }
        
        return res;
    }
};

/*
Rearrange String k Distance Apart   
aabbcc - k = 3
output - abcabc

aaabc = 3 , k = 3
output - ""

aaadbbcc , k = 2
output -  acabadbc , abacabcd

k = 2  ab  ac  abcd
a - 3  2    1
b - 2  1    1
c - 2  2    1
d - 1  1    1

k = 3   abc abc
a - 2   1   1
b - 2   1   1
c - 2   1   1

k = 3   abc 
a - 3   1
b - 1   0
c - 1   0
if count != k  return ""
*/

/*

I feel that the running time of this algorithm is O(n). The reason is that the only possible characters in the string are lower case letters, which makes the maximum size of the priority queue 26. We are doing one push and pop from the priority queue for each character in the string, which is O(n * (2 * log(26))). This reduces to O(n).

This is similar to how the other array based solution looks like it would be O(n^2), but it is not because they are doing a linear scan of a constant sized array.

*/