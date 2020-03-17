/*
i <= j , A[i] <= A[j] 
i <= j , A[i] >]/= A[j] 
*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int sz = A.size();
        if(sz==0 || sz == 1)
            return true;
        
        bool incr{false}, decr{false};
        for(int i{}; i < sz-1; ++i){
            if(A[i] < A[i+1]){
                incr = true;
            }
            else if(A[i] > A[i+1]){
                decr = true;
            }
        }
        return incr&& decr ? false : true;
    }
};


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int sz = A.size();
        if(sz==0 || sz == 1)
            return true;
        
        int i{};
        for(; i < sz-1; ++i){
            if(A[i] != A[i+1])
                break;
        }
        
        if(i+1 < sz && A[i] <= A[i+1]) {
            for(; i < sz-1; ++i) {
                if(A[i] > A[i+1])  // Increment
                    return false;
            }    
        }
        else {
            for(; i < sz-1; ++i) {
                if(A[i] < A[i+1])  // Decrement
                    return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int sz = A.size();
        if(sz < 2) {
            return true;
        }
        
        int first = A[0];
        int i{1};
        for(; i < sz; ++i) {
            int second = A[i];
            if(first > second) {
                break;
            }
            first = second;
        }
        if(i==sz){
            return true;
        }
        
        i=1;
        first= A[0];
        for(; i < sz; ++i) {
            int second = A[i];
            if(first < second) {
                break;
            }
            first = second;
        }
        if(i==sz){
            return true;
        }
        return false;
    }
};