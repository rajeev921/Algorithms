/*
[0,2]      - 2
[-2,3,-4]  - 24
[2,3,-2,4] - 6
[-2]       - 0
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
	int net_max{INT_MIN}, imax{1}, imin{1};
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                swap(imax, imin);
            }
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            
            net_max = max(net_max, imax);
        }
        return net_max;
    }
};












