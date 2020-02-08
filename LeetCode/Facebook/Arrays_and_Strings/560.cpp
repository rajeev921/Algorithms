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
