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
    TreeNode* node = NULL;
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root == NULL)
            return root;
        if(root->val == val)
            node = root;
        else
        {
            searchBST(root->left, val);
            searchBST(root->right, val);
        }
        return node;
    }
};