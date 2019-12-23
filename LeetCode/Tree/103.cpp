vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    if(root)  q.push(root);
    bool reverse = false;
    vector<vector<int>> zigzagResult;
    while(!q.empty()){
        int size = q.size();
        zigzagResult.push_back(vector<int>(size));
        for(int i=0; i<size; i++){
            int index = (reverse) ? size-i-1 : i;
            zigzagResult.back()[index] = q.front()->val;
            if(q.front()->left)  q.push(q.front()->left);
            if(q.front()->right)  q.push(q.front()->right);
            q.pop();
        }
        reverse = !reverse;
    }
    return zigzagResult;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // Runtime of recursion is much faster
public:
    int depth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return(max(depth(root->left), depth(root->right))+1);
    }
    void zizzagOrder(TreeNode* root, vector<int>& temp, int k, bool flip)
    {
        if(root == NULL)
            return;
        if(k == 0) {
            temp.push_back(root->val);    
        }
        else if(flip == false){
            --k;
            zizzagOrder(root->right, temp, k, flip);
            zizzagOrder(root->left, temp, k, flip);
        }
        else {
            --k;
            zizzagOrder(root->left, temp, k, flip);
            zizzagOrder(root->right, temp, k, flip);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        int height = depth(root);
        vector<vector<int>> result;
        bool flip{false};
        for(int i = 0; i < height; ++i)
        {
            vector<int> temp;
            zizzagOrder(root, temp, i, flip);
            result.push_back(temp);
            flip = !flip;
        }
        
        return result;
    }
};    