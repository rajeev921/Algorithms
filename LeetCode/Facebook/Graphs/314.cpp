/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]
Output:
[
  [9],
  [3,15],
  [20],
  [7]
]

Examples 2:

Input: [3,9,8,4,0,1,7]
Output:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
c/**
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(root==nullptr) {
            return output;
        }
        
        map<int, vector<int>> lookup;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        int min_val{INT_MAX}, max_val{INT_MIN};
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode* node = q.front().second;
                int level = q.front().first;
                min_val = min(min_val, level);
                max_val = max(max_val, level);    
                q.pop();
                               
                lookup[level].push_back(node->val);
                if(node->left) {
                    q.push({level-1, node->left});
                }
                if(node->right) {
                    q.push({level+1, node->right});
                }
            }
        }
        
        for(int i=min_val; i <= max_val; ++i) {
            output.push_back(lookup[i]);
        }
        return output;
    }
};

// small buggy solution
class solution {    
    void traverse(TreeNode* root, int level, map<int, vector<int>> &lookup) {
        if(root==nullptr){
            return;
        }

        lookup[level].push_back(root->val);           
        traverse(root->left, level-1, lookup);
        traverse(root->right, level+1, lookup);

    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }

        vector<vector<int>> out;
        map<int, vector<int>> lookup;

        traverse(root, 0, lookup);

        for(auto itr = lookup.begin(); itr != lookup.end(); ++itr) {
            out.push_back(itr->second);
        }

        return out;
    }
};    