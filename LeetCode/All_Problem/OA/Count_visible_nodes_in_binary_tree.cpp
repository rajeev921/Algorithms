#include <bits/stdc++.h>

using namespace std;

// TC - O(n)  , SC - O(n)
class Solution{
private:
    int count{};
private:
    void preOrder(Node* nd, int maxVal){
        if(nd == nullptr)
            return;

        if(nd->data > maxVal){
            ++count;
            count = max(nd->data, maxVal);
        }

        preOrder(nd->left, maxVal);
        preOrder(nd->right, maxVal);

        return;
    }
public:
    int countVisibleNodes(Node* nd) {
        
        preOrder(nd, INT_MIN);

        return count;
    }
};