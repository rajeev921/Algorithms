
// Another solution
class Solution{
public:
    unordered_map<int, vector<int>> lookup;
    Solution(vector<int>& nums) {
        for(int i{}; i <nums.size(); ++i) {
            lookup[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        if(lookup.find(target) != lookup.end()) {
            auto vec = lookup.at(target);
            return vec[rand()%vec.size()];
        }
        
        return 0;
    }    
};


// Fast Solution
class Solution {
public:
    vector<int> n;
    Solution(vector<int> nums) 
    {
        n = std::move(nums);
    }
    
    int pick(int target) 
    {
        int count{}, res = -1;
        for (int i{}; i < n.size(); ++i)
        {
            if(n[i] != target) 
                continue;
            if(++count == 1) 
                res = i;
            else
                if(!(rand()%count)) // if it is zero
                    res = i;
        }
        return res;
    }
};


/*

To those who don't understand why it works. Consider the example in the OJ
{1,2,3,3,3} with target 3, you want to select 2,3,4 with a probability of 1/3 each.

2 : It's probability of selection is 1 * (1/2) * (2/3) = 1/3
3 : It's probability of selection is (1/2) * (2/3) = 1/3
4 : It's probability of selection is just 1/3

So they are each randomly selected.

*/

class Solution {
vector<int> _nums;
public:
Solution(vector<int> nums) {
    _nums = nums;
}

int pick(int target) {
    int n = 0, ans = -1;
    for(int i = 0 ; i < _nums.size(); i++){
        if(_nums[i] != target) 
        	continue;
        if(n == 0){
        	ans = i; n++;
        }
        else{
            n++;
            if(rand() % n == 0){
            	ans = i;
            }// with prob 1/(n+1) to replace the previous index
        }
    }
    return ans;
}
};

/*
auto bounds = equal_range(nums_.begin(), nums_.end(), target);
        
        // The number of equal items is this:
        auto N = distance(bounds.first, bounds.second);

        // Could short-circuit if N == 1
        if(N == 1)
          return *bounds.first;

        // For return, can index off the bounds iterator:
        return nums_[(bounds.first - nums_.begin()) + rand() % N];    

class Solution {
public:
    vector<int> nums_;
    Solution(vector<int>& nums) {
        nums_ = std::move(nums);
        sort(nums_.begin(), nums_.end());
        srand(time(NULL));
    }
    
    int pick(int target) {
        int count{};
        int len = nums_.size();
        
        for(int i{}; i < len; i++) {
            if(target == nums_[i]) count++;
        }
        
        //int pickIndex = rand.nextInt(count);
        
        int pickIndex = rand()% static_cast<int>(count + 1);
        
        for(int i = 0; i < len; i++) {
            if(target == nums_[i]) {
                if(pickIndex-- == 0) return i;
            }
        }
        return 0; // shouldn't come here
    }
};        
*/
