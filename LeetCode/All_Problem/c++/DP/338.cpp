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
        
        vector<int> res;
        
        for(int i{}; i <= num; ++i) {
            int temp = countNoOfBit(i);
            res.push_back(temp);
        }
        return res;
    }
};