#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0;
        int j = height.size() -1;
        int max = 0;
        int depth = 0;
        
        while(i < j)
        {
            if(height[i] < height[j])
            {
                depth = height[i] * (j - i);
                std::cout <<"  i  "<< depth << std::endl;
                if(max < depth)
                {
                    max = depth;
                }
                ++i;
            }
            else{
                depth = height[j] * (j - i);
                std::cout <<"  j  "<< depth << std::endl;
                if(max < depth){
                    max = depth;
                }
                --j;
            }
                
        }
        
        return max;
    }
};

int main()
{
	std::vector<int> Input{1,8,6,2,5,4,8,3,7};

	Solution obj;

	std::cout << obj.maxArea(Input) << std::endl;

	return 0;
}