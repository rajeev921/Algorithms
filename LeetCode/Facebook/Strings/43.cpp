class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        vector<int> t(n1+n2, 0);
        
        for(int i{n1-1}; i>=0; --i){
            for(int j{n2-1}; j >=0; --j) {
                int mul = (num1.at(i) - '0') * (num2[j] - '0');
                int p1 = i+j, p2 = i+j+1;
                int sum = mul + t[p2];
                
                t[p1] += sum/10;
                t[p2] = sum%10;
            }
        }
        
        string res;
        int i{};
        for(; i < t.size(); ++i){
            if(t[i]==0)
                continue;
            else
                break;
        }
        
        if(i==t.size())
            return "0";
        
        while(i < t.size()){
            res += (t[i]+'0');
            ++i;
        }
        
        return res;
    }
};

/*
123
456

i = 2, j = 2, 6*3 = 18 Now p1 = i+j = 4, p2 = i+j+1 = 5
[0,0,0,0,0,0] = [0,0,0,0,1,8]

i = 2, j = 1,  Now p1 = i+j = 3, p2 = i+j+1 = 4
sum = mul + t[p2] = 5*3 +1 = 16
[0,0,0,0,0,0] = [0,0,0,1,6,8]
---------------------------------------------------
index 1		1 2 3  index i
index 0		  4 5  index j
-------------------------
			  1 5
			1 0 
		  0 5
    ---------------------
			1 2
id[1,2]   0 8	    indices[i+j, i+j+1]
        0 4
    ---------------------		
     id[0,1,2,3,4]
	 [p1,p2]
<-----------------------	 
*/