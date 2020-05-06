/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Recursive PostOrder -  TC - O(n) , SC - O(n)
class Solution {
public:
    void flatten(TreeNode *root) {
        flatten(root, nullptr);
    }
private:
    TreeNode* flatten(TreeNode* root, TreeNode* prev) {
        if(root==nullptr){
            return prev;
        }
        prev = flatten(root->right, prev);
        prev = flatten(root->left, prev);
        
        root->right = prev;
        root->left = nullptr;
        prev = root;
        
        return prev;
    }
};
 
// Loop  TC - O(n) , SC - O(1)
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root==nullptr){
            return;
        }
        
        while(root){
            if(root->left && root->right){
                TreeNode* t = root->left;
                while(t->right)
                    t = t->right;
                t->right = root->right;
            }
            if(root->left){
                root->right = root->left;
                root->left = nullptr;
            }
            root=root->right;
        }
        return;
    }        
};
/*
    1
   / \
  2   5
 / \   \
3   4   6

    1
     \
     2
     / \
    3   4
         \
          5
           \
            6
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6

*/