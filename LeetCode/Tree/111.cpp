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
    int minDepth(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            ++count;
            for(int i = 0; i < sz; ++i) {
                TreeNode* t = q.front();
                q.pop();
                if(!(t->left) && !(t->right)) {
                    return count;
                }
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
        }
        return count;
    }
};