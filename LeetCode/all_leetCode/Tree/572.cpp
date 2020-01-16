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
    bool isSame(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr) {
            return true;
        }
        if( (s&&t) && (s->val == t->val) &&(isSame(s->left, t->left)) &&(isSame(s->right, t->right))) {
            return true;
        }
        
        return false;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isSame(s, t)) {
          return true;  
        }
        if(s->left && isSubtree(s->left, t)) {
            return true;
        }
        if(s->right && isSubtree(s->right, t)) {
            return true;    
        }
        return false;
    }
};

class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& t) {
        if(root == NULL) {
            return;
        }
        preOrder(root->left, t);
        t.push_back(root->val);
        preOrder(root->right, t);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s ==NULL && t ==NULL) {
          return true;  
        }
        if(s == NULL || t == NULL) {
          return false;  
        }
        
        preOrder(s, s_tree);
        preOrder(t, t_tree);
        int i{}, j{};
        int len = t_tree.size();
        while(i < s_tree.size() && j < t_tree.size()) {
            if(s_tree[i] == t_tree[j]) {
                --len;
                ++j;
            }
            else {
                return false;
            }
            ++i;
        }
        if(j == t_tree.size()) {
            return true;
        }
        
        return false;
    }
public:
    vector<int> s_tree;
    vector<int> t_tree;
};