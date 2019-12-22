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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValid(root->left, root->val, true) || !isValid(root->right, root->val, false)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
    
    bool isValid(TreeNode* root, int bound, bool isLeft){
        return !root || (isLeft ? root->val < bound : root->val > bound ) && isValid(root->left, bound, isLeft) && isValid(root->right, bound, isLeft);
    }
};

//In-order, recursive, O(n), refered from here.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return isValid(root, pre);
    }
    
    bool isValid(TreeNode* root, TreeNode* &pre){
        if(!root) return true;
        if(!isValid(root->left, pre)) return false;
        if(pre && root->val <= pre->val) return false;
        pre = root;
        return isValid(root->right, pre);
    }
};

// In-order, iterative, O(n), refered from here.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* pre = NULL;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(pre && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};

class Solution {
    bool isBst{false};
public:
    bool isValidBST(TreeNode* root) {
    return dfs_valid(root, LONG_MIN, LONG_MAX);
}
bool dfs_valid(TreeNode *root, long low, long high) {
    if (!root) return true;
    return low < root->val && root->val < high && dfs_valid(root->left, low, root->val)
            && dfs_valid(root->right, root->val, high);
}
};