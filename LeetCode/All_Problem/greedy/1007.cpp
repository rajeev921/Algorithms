class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size() == 0 && B.size() == 0) {
            return 0;
        }
        else if(A.size()==0 || B.size()==0) {
            return -1;
        }
        
        int res = A.size()+1;
        
        for(int i = 1; i <= 6; ++i) {
            int first{}, second{}, k{};
            
            while(k < A.size() && (A[k] == i || B[k] ==i)) {
                if(A[k] != i){
                    ++first;
                }
                else if(B[k] != i) {
                    ++second;
                }
                ++k;
            }
            if(k == A.size()) {
                res = min(res, min(first, second));
            }
        }
        if(res==A.size()+1){
            return -1;
        }
        return res;
    }
};

/*
3, 5, 1, 2, 3    - 2, 1, 2, 4, 2, 2  
3, 6, 3, 3, 4    - 5, 2, 6, 2, 3, 2


*/