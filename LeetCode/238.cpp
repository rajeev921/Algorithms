class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int>products(N, 0);
        int p=1;
        for(int i=0;i<N;++i) {
          products[i]=p;
          p*=nums[i];
        }

        p=1;
        for(int i=N-1;i>=0;--i) {
          products[i]*=p;
          p*=nums[i];
        }
        
        return products;
    }
}; 