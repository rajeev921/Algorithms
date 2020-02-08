
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 time Complexity - O(n)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        while(root != nullptr) {
            if(root->left && root->right) {
                TreeNode* t = root->left;
                while(t->right){
                    t = t->right;
                }
                t->right = root->right;
            }
            if(root->left){
                root->right = root->left;
            }
            root->left = nullptr;
            root= root->right;
        }
        return;
    }
};

