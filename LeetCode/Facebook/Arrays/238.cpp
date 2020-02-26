class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        if(sz <  3){
            if(sz < 1)
                return {};
            if(sz==2)
                return {nums[1], nums[0]};   
        }
        
        int t{1};
        vector<int> product(sz, 0);
        for(int i{}; i < sz; ++i) {
            product[i]=t;
            t *= nums[i];
        }
        
        t=1;
        for(int i=sz-1; i >=0; --i){
            product[i] *=t;
            t *= nums[i];
        }
        
        return product;
    }
};
/*
Input :
[1, 2, 3, 4]
Output :
[24, 12, 8, 6]

i = 0 t = 1, 
i = 1 t = 1, 
i = 2 t= 2, 
i = 3 t = 3

[1, 1, 2, 6]
t = 24

again t = 1 
i = 3, t = 1  = 1*6  = 6 
i = 2, t = 4  = 4*2  = 8
i = 1. t = 12 = 12*2 = 24
i = 0, t = 24 = 24*1 = 24
[24, 12, 8, 6]

*/
