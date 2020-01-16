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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return root;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i{}; i < sz; ++i) {
                TreeNode* t= q.front();
                q.pop();
                swap(t->left, t->right);
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
            
        }
        
        return root;
    }
};

// Solution 2 -- Recursive 

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            invertTree(root->left);
            invertTree(root->right);
            std::swap(root->left, root->right);
        }
        return root;
    }
};