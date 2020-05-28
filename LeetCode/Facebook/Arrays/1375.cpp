/*
right is the number of the right most lighted bulb.

Iterate the input light A,
update right = max(right, A[i]).

Now we have lighted up i + 1 bulbs,
if right == i + 1,
it means that all the previous bulbs (to the left) are turned on too.
Then we increment res
*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int right{}, res{}, n = light.size();
        
        for (int i{}; i < n; ++i)
            res += (right = max(right, light[i])) == i + 1;
        
        return res;
    }
};

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        vector<bool> on(light.size(),false);
        int maxBlue=0,result=0;
        for(int i=0;i<light.size();i++)
        {
            on[light[i]-1]=true;
            while(maxBlue<light.size()&&on[maxBlue])   //Increase the end of blue bulbs sequence starting from 0,
                maxBlue++;
            result+=maxBlue==i+1;                  		//If number of blue bulbs is equal to number of switched on bulbs.
        }
        return result;
    }
};

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size(), ans{}, currMax{};
        long currSum{};
        
        for(int i = 0; i < n; i++) {
            currMax = max(currMax, light[i]);
            currSum += (long)light[i];
            if(currSum == ((long)currMax * (currMax + 1)) / 2) ans++;
        }
        
        return ans;
    }
};

