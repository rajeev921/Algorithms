class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) {
            return 0;
        }
        if(n <= 3) {
            return n;
        }
        int allSteps{}, oneStep{}, twoStep{};
        oneStep = 2;
        twoStep = 1;
        
        for(int i= 2; i<n; ++i) {
            allSteps = oneStep + twoStep;
            twoStep = oneStep;
            oneStep = allSteps;
        }
     
        return allSteps;
    }
};