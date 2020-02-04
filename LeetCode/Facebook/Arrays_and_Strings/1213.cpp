/*
Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.
Example 1:
Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.

Constraints:

    1 <= arr1.length, arr2.length, arr3.length <= 1000
    1 <= arr1[i], arr2[i], arr3[i] <= 2000
*/
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
         int i{}, j{}, k{};
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                result.push_back(arr1[i]);
                i++;
                j++;
                k++;
            } else if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr2[j] < arr3[k]) {
                j++;
            } else k++;
        }

        return result;
    }
};

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        
        map<int, int> lookup;
        int i{};
        vector<int> res;
        
        while(i < arr1.size()) {
            int key = arr1[i];
            if(lookup.find(key)==lookup.end()) {
                lookup[key] = 1;
                cout << key << " ";
            }      
            ++i;
        }
        
        i = 0;
        while(i < arr2.size()) {
            int key = arr2[i];
            if(lookup.find(key)!=lookup.end()) {
                lookup[key]++;
                cout <<key <<"  ";          
            }      
            ++i;
        }
        
        i = 0;
        while(i < arr3.size()) {
            int key = arr3[i];
            if(lookup.find(key)!=lookup.end()) {
                lookup[key]++;
                cout <<key <<"  ";
            }      
            ++i;
        }
        
        for(auto itr=lookup.begin(); itr != lookup.end(); ++itr) {
            if(itr->second==3) {
                res.push_back(itr->first);
                cout <<itr->first <<"  ";
            }
        }
        
        return res;
    }
};

//