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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode* t = q.front();
                q.pop();
                if(i==sz-1) {
                    res.push_back(t->val);
                }
                if(t->left) {
                    q.push(t->left);    
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
        }
        return res;
    }
public:
    vector<int> res;
};