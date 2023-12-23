class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b)->bool{
           if(a[0]>b[0])
               return true;
            else if(a[0]==b[0])
            {
                return a[1]<b[1];
            }
            else
                return false;
        });
        list<vector<int>> li;
        for(auto& p: people)
        {   auto pos = li.begin();
            advance(pos, p[1]);   // you can't use iterator + int val for list container like the way you do for vector
            li.insert(pos, p);
        }
        return vector<vector<int>>(li.begin(), li.end());
    }
};
/*
Solution :

We insert people one by one into an empty array. The number k is the position we need to insert. For everyone, we should first insert the higher h person. For the person who has same h we should first insert the person has small k value. For each inserted person, it takes O(n) time to move the person behind him back one position, so it will take the O(n^2) time for all people.
E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
sort: [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
step1: [[7,0]]
step2: [[7,0], [7,1]]
step3: [[7,0], [6,1], [7,1]]
step4: [[5,0], [7,0], [6,1], [7,1]]
step5: [[5,0], [7,0], [5,2], [6,1], [7,1]]
step6: [[5,0], [7,0], [5,2], [4,4], [6,1], [7,1]]

*/