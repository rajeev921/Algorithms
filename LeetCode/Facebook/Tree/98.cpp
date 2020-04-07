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

// Another Solution

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
