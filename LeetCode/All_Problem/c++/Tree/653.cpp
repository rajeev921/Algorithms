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
    unordered_map<int, int> lookup;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL || k == 0)
            return false;
        if(lookup.count(k - root->val)) return true;
        lookup[root->val]++;
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
