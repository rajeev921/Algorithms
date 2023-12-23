// TC - O(n*noOf1's)
class Solution {
public:
    int countNoOfBit(int n){
        int count {};
        while(n  > 0){
            count++;
            n = n&(n-1);
        }
        
        return count;
    }
    vector<int> countBits(int num) {
        
        vector<int> res(num+1, 0);
        
        for(int i{1}; i <= num; ++i) {
            res[i] = countNoOfBit(i);
        }
        return res;
    }
};


// TC - O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};