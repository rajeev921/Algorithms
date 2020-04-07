// This solution has O(logN^2) time complexity.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        
        int dvd = abs(dividend), dvs = abs(divisor);
        int res{}, x{};
        
        while (dvd - dvs >= 0) {
            x = 0;
            while(dvd - (dvs << 1 << x) >= 0)
                ++x;
            res += 1 << x;
            dvd -= dvs << x;
        }
        return (dividend > 0) == (divisor > 0) ? res : -res;
    }
};


// Not working <solution
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        if(divisor == 1)
            return dividend;
        
        int a = abs(dividend), b = abs(divisor), res{};
        for (int x = 31; x >= 0; x--){
            if ((signed)((unsigned)a >> x) - b >= 0)
                res += 1 << x;
            a -= b << x;
        }
        
        return (dividend > 0) == (divisor > 0) ? res : -res;
    }
};

// TC O(logn*logn) // use of long instead of int
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        else if(divisor == 1){
            return dividend;
        }

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long dvs = labs(divisor);
        long dvd = labs(dividend);
        int count{};
        
        while(dvd >= dvs){
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        
        return count*sign;
    }
};
