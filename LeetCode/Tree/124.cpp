class Solution {
public:
    int maxSum(TreeNode* root, int& sum)
    {   
        if(root== NULL)
            return 0;
        int l = maxSum(root->left, sum);
        int r = maxSum(root->right, sum);
        if(!(root->left && root->right))
        {
            sum = root->val;
            return sum;
        }
            return root->val;
        int  k = l + r + root->val;
        sum = max(sum, k);    
        return max(l, r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        maxSum(root, sum);
        return sum;
    }
};

// Working Solution Below


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
private:
    int traverse(TreeNode* root, int& maxSum)
    {
        if(!root) return 0;
        int lMax = max(0, traverse(root->left, maxSum));
        int rMax = max(0, traverse(root->right, maxSum));
        maxSum = max(maxSum, lMax+rMax+root->val);
        return max(lMax, rMax)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        traverse(root, maxSum);
        return maxSum;
    }
};