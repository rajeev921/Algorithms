/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
        {
            return out;
        }
        else{
            inorderTraversal(root->left);
            out.push_back(root->val);
            inorderTraversal(root->right);    
        }
        return out;
    }
    vector<int> out;
};
//Iterative approach --- need to fix some error for some case 
// Time complexity - O(n) , Space Complexity -O(1)
// Morris Traversal -Threaded Binary Tree



//Iterative approach --- need to fix some error for some case 
// Time complexity - O(n) , Space Complexity -O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        
        if(root == NULL)
        {
            return out;
        }
        
        TreeNode* temp = root;
        stack<TreeNode*> st;    
        st.push(temp);
        while(temp != NULL && (st.empty() == false))
        {   
            if(temp->left)
            {
                st.push(temp->left);
                temp = temp->left;
                continue;
            }
            else if(temp->left == NULL)
            {
                temp = st.top();
                st.pop();
                out.push_back(temp->val);
                //std::cout << temp->val<<"  ";
            }
            if(temp->right)
            {
                st.push(temp->right);
                temp = temp->right;
            }
        }
        return out;
    }
};