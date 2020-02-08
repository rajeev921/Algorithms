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
        return isValidBST(root, NULL, NULL);
    }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};

// Iterative Solution -
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
			return true;
		stack<TreeNode*> st;
		TreeNode* prev=nullptr;
		while(root!= nullptr || !st.empty()) {
			while(root != nullptr) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(prev != nullptr && root->val <= prev->val)
                return false;
            prev = root;
            root = root->right; 
		}
		return true;
    }
};
