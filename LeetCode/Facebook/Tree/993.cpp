class Solution {
public:
    TreeNode* xParent = NULL, *yParent = NULL;
    int xDepth = -1, yDepth = -2;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, x, y, 0);
        return xDepth == yDepth && xParent != yParent;
    }
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int depth) {
        if (root == NULL) return;
        if (x == root->val) {
            xParent = parent;
            xDepth = depth;
        } else if (y == root->val) {
            yParent = parent;
            yDepth = depth;
        } else {
            dfs(root->left, root, x, y, depth + 1);
            dfs(root->right, root, x, y, depth + 1);
        }
    }
};

// Another Solution
class Solution {
    int xDepth = -1;
    int yDepth = -1;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root, x, y, 0);
        return xDepth != -1 && xDepth == yDepth;
    }
    
    void solve(TreeNode *root, int x, int y, int depth){
        if(!root) return;
        if(
            root->left &&
            root->right && 
            (root->left->val == x || root->left->val == y) &&
            (root->right->val == x || root->right->val == y)
        ) return;
        
        if(root->val == x){
            xDepth = depth;
            return;
        }
        if(root->val == y){
            yDepth = depth;
            return;
        }
        
        solve(root->left, x, y, depth+1);
        solve(root->right, x, y, depth+1);
    }
};