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
    void swap(TreeNode* root)
    {
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        else {
            invertTree(root->left);
            invertTree(root->right);
            if(root->left && root->right)
                swap(root);
        }
        return root;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        else {
            stack<TreeNode*> st;
            st.push(root);
            while(!st.empty())
            {
                TreeNode* cur = st.top();
                st.pop();
                if(cur)
                {
                    st.push(cur->left);
                    st.push(cur->right);
                    swap(cur->left, cur->right);                 
                }
            }
        }
        return root;
    }
};