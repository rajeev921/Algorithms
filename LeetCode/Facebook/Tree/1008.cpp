class Solution {
public:
    TreeNode* Preorder(vector<int>& A, int bound = INT_MAX) {
        if (i == A.size() || A[i] > bound) 
            return NULL;
        
        TreeNode* root = new TreeNode(A[i++]);
        root->left = Preorder(A, root->val);
        root->right = Preorder(A, bound);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return Preorder(preorder, INT_MAX);
    }
private:
    int i = 0;
};