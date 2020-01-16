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
    int maxDepth(TreeNode* root) {
       return root ? 1 + max(maxDepth(root -> left), maxDepth(root -> right)) : 0;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
       if(root==NULL)
           return 0;
        
        queue<TreeNode*> q;
        int depth{0};
        q.push(root);
        
        while(!q.empty())
        {
            int idx = q.size();
            for(int i = 0; i < idx; ++i)
            {
                TreeNode* cur = q.front();
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
                q.pop();
            }
			++depth;
        }
        return depth;        
    }
};