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
    void inorder(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left);    
        --count;
        if(count == 0) {
            res = root->val;    
        }
        inorder(root->right);    
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(k  < 1) {
            return 0;
        } 
        count = k;
        inorder(root);
        return res;
    }
public:
    int count;
    int res;
};