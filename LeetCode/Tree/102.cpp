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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int idx = q.size();
            vector<int> res;
            for(int i = 0; i < idx; ++i) {
                TreeNode* cur = q.front();
                res.push_back(cur->val);
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            result.push_back(res);    
        }
        return result;    
    }
};