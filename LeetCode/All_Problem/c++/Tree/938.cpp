/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==nullptr){
            return 0;
        }
        if(root->val >= L && root->val <= R){
            sum += root->val;
        }
        rangeSumBST(root->left, L, R);
        rangeSumBST(root->right, L, R);
        
        return sum;    
    }
public:
    int sum{};
};

// Iterative using stack  , TC - O(n), SC - O(n)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==nullptr){
            return 0;
        }
        
        int sum{};
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top(); 
            st.pop();
            if(temp->val >= L && temp->val <= R) {
                sum += temp->val;
            }
            if(L < temp->val && temp->left){
                st.push(temp->left);
            }
            if(R > temp->val && temp->right)
                st.push(temp->right);
        }
        
        return sum;
    }
};

class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        if(root->left)
            rangeSumBST(root->left, L, R); 
        if(root->val >= L && root->val <= R)
            sum += root->val;
        if(root->right)
            rangeSuamBST(root->right, L, R);
        return sum;
    }
};

// another solution

class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        if (root == null) 
            return 0; // base case.
        if (root->val < L) 
            return rangeSumBST(root->right, L, R); // left branch excluded.
        if (root->val > R) 
            return rangeSumBST(root->left, L, R); // right branch excluded.
        return root->val + rangeSumBST(root->right, L, R) + rangeSumBST(root->left, L, R); // count in both children.
    }
};