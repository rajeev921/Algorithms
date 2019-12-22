class Solution {
public:
    int tribonacci(int n) {
        if(n < 1)
            return 0;
        else if(n < 3)
            return 1;
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        int tn = t0 + t1 + t2;
        for(int i=3; i < n; ++i) {
            t0 = t1;
            t1 = t2;
            t2 = tn;
            tn = t0 + t1 + t2;
        }
        
        return tn;
    }
};