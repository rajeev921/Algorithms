//TC - O(n) , SC - O(k)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum{}, pre{};
        unordered_set<int> modk;
        
        for (int i{}; i < n; ++i) {
            sum += nums[i];
            int mod = (k == 0 ? sum : sum % k);
            if (modk.find(mod) != modk.end() ) 
                return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};
/*                  Explanation

1. store mod result in a set
2. delay the storing by 1 loop so that the length subarray of is > 1


This is one of those magics of remainder theorem
(a+(n*x))%x is same as (a%x)
For e.g. in case of the array [23,2,6,4,7] the running sum is [23,25,31,35,42] and the remainders are [5,1,1,5,0]. We got remainder 5 at index 0 and at index 3. That means, in between these two indexes we must have added a number which is multiple of the k. Hope this clarifies your doubt :)
*/

//TC - O(n) , SC - O(k) = Not working for few corner case
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        int sum{};
        unordered_map<int> lookup;

        for(int i{}; i < sz; ++i){
            sum += nums[i];
            if(k != 0)
                sum %= k;
            
            if(lookup.find(sum) != lookup.end()){
                int prev = lookup.at(sum);
                if(i - prev > 1)
                    return true;
            }
            else
                map[sum] = i;
        }

        return false;
    }
};


// Not working solution 
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz < 2 )
            return false;
        for(int i{1}; i < sz; ++i){
            if(nums[i] ==0 && nums[i-1] == 0)
                return true;
        }
        if(k == 0)
            return false;
        if(k < 0)
            k = -k;
        
        unordered_map<int, int> lookup;
        int sum{}; 
        lookup[0] = -1;
        
        for(int i{}; i < sz; ++i) {
            sum =  nums[i];
            if(k != 0)
                sum %= k;
            
            if(lookup.find(sum) != lookup.end()){
                int prev = lookup.at(sum);
                if(i - prev > 0)
                    return true;
            }
            else
                lookup[sum] = i;
        }
        
        return false;
    }
};