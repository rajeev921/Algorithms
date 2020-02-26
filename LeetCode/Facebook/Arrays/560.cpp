class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        
        
        int count{};
        for(int i{}; i < sz; ++i){
            int sum{};
            for(int j=i; j < sz; j++) {
                sum += nums[j];
                if(sum==k){
                    ++count;
                }
            }
        }
        
        return count;
    }
};
/*Assumtion
all subset need to be check , no break after getting sum
*/
/*
for i, cum is the sum of nums[0] + nums[1] + ... + nums[i]. Assuming there is an item called 
nums[j] in nums[0] + nums[1] + ... nums[j] + ... + nums[i], 
if nums[0] + nums[1] + ... + nums[j] equals to cum - k, 
then, the sum of subarray nums[j + 1] + nums[j + 2] + ... + nums[i] 
equals to cum - (cum - k) = k, it is one of the subarray which we 
are looking for. rec[cum - k] is the number of the subarray which 
begins at index 0 with sum cum - k.
*/
// OPTIMIZE SOLUTION -

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        
		unordered_map<int, int> lookup;
        int cur_sum{}, count{};
		lookup[0]++;
        for(int i{}; i < sz; ++i){
            cur_sum += nums[i];
			if(lookup.find(cur_sum-k) != lookup.end())
				count += lookup[cur_sum-k];
			lookup[cur_sum]++;
        }
        
        return count;
    }
};

/*
any idea guys, why do we have to initialize map like preSum.put(0, 1); .........I mean how would we know to do this if approaching this solution for first time? I got most of the things in for loop correct (ofc i had seen "two sum" problem, "Maximum Size Subarray Sum Equals k" under amazon problem before and used similar ideas here...)...still don't get why we initialize the map...

##################

I see ...After spending some time on the analysis, I found the reason behind having initialize preSum.put(0,1)....it is for those (sum - k) == 0 calculations which are valid subarrays but need to get counted. e.g. if k = 7 and sum = 7 (at second element for array is : 3, 4, 3, 8) at some iteration.....then sum - k = 0....this 0 will get counted in statement result += preSum.get(sum - k);

#############

So in conclusion, the initial entry preSum.put(0, 1) can be exchanged with statement :
if (sum == k) count++;
we can put it just below sum += nums[i]; statement. This will make code more intuitive...as we are trying to find the sum which matches to k!
*/
