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
    void rangeSum(TreeNode* root, int& sum, int L, int R) {
        if(root->val>= L && root->val<= R) {
            sum += root->val;
        }
        if(root->left)
            rangeSum(root->left, sum, L, R);
        if(root->right)
            rangeSum(root->right, sum, L, R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root==nullptr) {
            return 0;
        }
        int sum{};
        rangeSum(root, sum, L, R);
        
        return sum;
    }
};