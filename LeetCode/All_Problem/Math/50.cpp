class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1)
            return x;
        
        double res{1.0};
        if( n < 0) {
            x = 1/x;
            n = -(n+1);//for Integer.MIN_VALUE
            res = res*x;
        }
        
        /*
            if(abs(x-0.0) < 0.0000001) 
                return 0.0;
            if(abs(x-1.0) < 0.0000001) 
                return 1.0;
        */
        
        while (n>0){
            if((n&1) ==1) {//if n = 19,n=10011 then answer should
                //multiply x^(2^0) when the last digital is 1, and then
                //multiply x^(2^1) when the last digital is 1, and then
                //Finally, multiply x^(2^4).
                res = res * x;         
            }
            x = x* x;
            n>>=1;
        }
        return res;
    }
};