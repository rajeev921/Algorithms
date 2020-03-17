class Solution {
public:
    bool binary_Search(vector<vector<int>>& matrix, int row, int end, int target) {
        int start = 0;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(matrix[row][mid] == target) {
                return true;
            }
            else if(target > matrix[row][mid]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size()==0) 
        {
            return false;
        }
        
        
        for(int i = 0; i < matrix.size(); ++i) {
            int n = matrix[i].size()-1;
            
            int start = matrix[i][0];
            int end = matrix[i][n];
            
            if(target >= start && target <= end) {
                return binary_Search(matrix, i, n, target);
            }    
        }
        
        return false;
    }
};