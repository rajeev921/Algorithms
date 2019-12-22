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