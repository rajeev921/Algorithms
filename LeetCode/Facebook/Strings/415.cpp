/*
class Solution {
public:
    void reverseString(string& str){
        int len = str.size();
        int i{};
        --len;
        
        while(i < len){
            swap(str[i++], str[len--]);
        }
        return;
    }
    string addStrings(string num1, string num2) {
        int sz_1 = num1.size(), sz_2 = num2.size();
        string res;
        
        int i{}, j{}, carry{};
        
        
        reverseString(num1);
        reverseString(num2);
        
        while(i < sz_1 || j < sz_2) {
            int val_1 = i < sz_1 ? (num1[i++] - '0') : 0;
            int val_2 = j < sz_2 ? (num2[j++] - '0') : 0;
            int sum = val_1 + val_2 + carry;
            res += (sum%10 + '0');
            carry = sum/10;
        }
        if(carry != 0)
            res += (carry + '0');
        reverseString(res);
        
        return res;
    }
};

// Another Solution
class Solution {
    void reverseString(string& str){
        int len = str.size();
        int i{};
        --len;
        
        while(i < len){
            swap(str[i++], str[len--]);
        }
        return;
    }
public:
    string addStrings(string num1, string num2) {
        int sz_1 = num1.size(), sz_2 = num2.size();
        string res; 
        int i{sz_1-1}, j{sz_2-1}, carry{};
        
        while(i >=0 || j >=0) {
            int val_1 = i >=0 ? (num1[i--] - '0') : 0;
            int val_2 = j >=0 ? (num2[j--] - '0') : 0;
            int sum = val_1 + val_2 + carry;
            res += (sum%10 + '0');
            carry = sum/10;
        }
        if(carry != 0)
            res += (carry + '0');
        reverseString(res);
        
        return res;
    }
};
*/

#include <iostream>
#include <string>

// Add 2 string containing decimal 
/*  Example 1: str1 = "123.52" and str2 = "11.2", output should be "134.72"
    Example 2: str1 = "110.75" and str2 = "9", output should be "119.75"
*/

class Solution {
    void reverseString(string& str){
        int len = str.length();
        int i{};
        --len;
        
        while(i < len){
            swap(str[i++], str[len--]);
        }
        return;
    }

    string addAllStrings(string num1, string num2) {
        int sz_1 = num1.size(), sz_2 = num2.size();
        string res; 
        int i{sz_1-1}, j{sz_2-1}, carry{};
        
        while(i >=0 || j >=0) {
            int val_1 = i >=0 ? (num1[i--] - '0') : 0;
            int val_2 = j >=0 ? (num2[j--] - '0') : 0;
            int sum = val_1 + val_2 + carry;
            res += (sum%10 + '0');
            carry = sum/10;
        }
        if(carry != 0)
            res += (carry + '0');
        reverseString(res);
        
        return res;
    }

    int addCount(string str){
        int i{}, count{}, len = str.length();
        bool flag{false};

        while(i < len){
            if(str[i] == '.'){
                flag = true;
                ++count;
                ++i;
                continue;
            }
            if(flag==true){
                ++count1;
            }
            ++i;
        }

        return {idx, count};
    }

    string addZeros(string str, int count) {
        string res = str;
        while(count > 0){
            str += '0';
            --count;
        }
    }

    string addStrings(string& num1, string& num2){

        int len1 = num1.size(), len2 = num2.size();
        int i{}, j{}, count1{}, count2{};
        
        cout << " Before doing" << num1 <<"    " << num2 <<endl;

        auto pr1 = addCount(num1);
        auto pr2 = addCount(num2);

        if(pr1.second > pr2.second){
            int diff = pr1.second - pr2.second;
            // add no of zeros in num1
            num2 = addZeros(num2, diff)
        } else {
            int diff = pr2.second - pr1.second;
            // add no of zeros in num2
            num1 = addZeros(num1, diff)
        }

        cout << " After doing " << num1 <<"    " << num2 <<endl;

        return addAllStrings(num1, num2);
        /*
        num1 = "." + num1;
        num2 = "." + num2;
        stringstream ss(num1), ss(num2);

        string num1_dec, num1_dec'
        string num1_after_dec, num2_after_dec;


        add2String()
        */
    }
};
