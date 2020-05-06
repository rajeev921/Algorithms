class Solution {
public:
    int countAllSmaller(vector<int>& nums, int cur, int start, int end) {
        int count{};
        
        while(start < end) {
            if (nums[start] < cur) {
                ++count;
            }
            ++start;
        }   
        return count;
     }
    
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0) {
            return vector<int>{};
        }
        if(nums.size()==1) {
            return vector<int>{0};
        }
        
        int n = nums.size();
        vector<int> count(n, 0);
        int i = 0;
        for(; i < n-1; ++i){
            count[i] = countAllSmaller(nums, nums[i], i, n);
        }
        count[i] = 0;
        
        return count;
    }
};

// Optimize Solution - Using Binary Index Tree

class Solution {
    vector<int> bit;
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        bit.resize(nums.size()+1, 0);
             
        //get the ordered-index-array
        vector<int> sorted_nums(nums);
        unordered_map<int, int> dict;
        sort(sorted_nums.begin(), sorted_nums.end());
             
        for(int i=0; i<nums.size(); i++){
            dict[sorted_nums[i]] = i+1;
        }
             
        for(int i=nums.size()-1; i>=0; i--){
            //count the smaller numbers less than nums[i] , so use bit_sum(dict[nums[i]-1)
            result[i]=bit_sum(dict[nums[i]]-1);
            bit_add(dict[nums[i]], 1);
        }
     
    return result;
    }
         
    int bit_last(int i){
        return i&-i;
    }
         
    void bit_add(int i, int val){
        i++;
        while(i<bit.size()){
            bit[i]+=val;
            i=i+bit_last(i);
        }
    }
         
    int bit_sum(int i){
        i++;
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i=i-bit_last(i);
        }
        return sum;
    }
};