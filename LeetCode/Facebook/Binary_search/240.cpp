// TC - O(n*logm)
class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int i, int target) {
        int end = matrix[i].size()-1;
        int start{};
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(matrix[i][mid] == target)
                return true;
            else if(matrix[i][mid] > target){
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        for(int i{}; i < row; ++i){
            bool found = binarySearch(matrix, i, target);
            if(found == true)
                return true;
        }
        
        return false;
    }
};

// TC - O(n+m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    	int row = matrix.size();
        if(row==0)
            return 0;
        int col = matrix[0].size();
        if(col==0)
            return 0;
        
        int i = row-1,j =0;
        while(i>=0&&j<=col-1)
        {
            if(target>matrix[i][j])
            {
                j++;
            }
            else if(target<matrix[i][j])
            {
                i--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};