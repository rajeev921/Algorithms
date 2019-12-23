class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {    
        int start = 0;
        int end = A.size()-1;
        
        while(start <= end) {
            int mid = start + (end- start)/2;
            
            if(A[mid] > A[mid+1] && A[mid] > A[mid-1]) {
                return mid;
            }
            else if(A[mid] > A[mid+1]) {
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        return 0;
    }
};

// Faster solution

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return distance(A.begin(), max_element(A.begin(), A.end()));
    }
};        