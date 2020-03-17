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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr) {
            return 0;
        }
        int max = 0;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        int cur_level = 1;
        while(!q.empty()) {
            int cur_sum = 0;
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode* t = q.front();
                q.pop();
                cur_sum += t->val;
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
            if(cur_sum > max) {
                max = cur_sum;
                level = cur_level;
            }
            ++cur_level;
        }
        
        return level;
    }
};