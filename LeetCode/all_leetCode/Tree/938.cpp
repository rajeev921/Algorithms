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
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        if(root->left)
            rangeSumBST(root->left, L, R); 
        if(root->val >= L && root->val <= R)
            sum += root->val;
        if(root->right)
            rangeSumBST(root->right, L, R);
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

//iterative 
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        stack<TreeNode*> stk;
        stk.push(root);
        int sum = 0;
        while (!stk.empty()) {
            TreeNode* n = stk.top();
            stk.pop();
            if (n == nullptr) { continue; }
            if (n->val > L) { 
                stk.push(n->left); }
            if (n->val < R) { 
                stk.push(n->right); }
            if (L <= n->val && n->val <= R) { 
                sum += n->val; }
        }
        return sum;
    }
};