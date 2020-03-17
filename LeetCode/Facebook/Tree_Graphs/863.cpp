/* 
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
    void buildTree(TreeNode* root, TreeNode* parent) {
        if(root == nullptr) {
            return;
        }
        if(lookup.find(root) == lookup.end()) {
            lookup[root] = parent;
        }

        buildTree(root->left, root);
        buildTree(root->right, root); 
    }
    vector<int> distance(TreeNode* target, int k) {
        vector<int> res;
        
        bool visited[1000]{false};
        static queue<TreeNode*> q;
        q.push(target);
        visited[target->val] = true;
        --k;
        
        while(!q.empty()) {
            if(k == 0) {
                break;
            }
            int sz = q.size();
            for(int i =0; i < sz; ++i) {
                TreeNode* t = q.front();
                q.pop();

                if(t->left && !visited[t->left->val]) {
                    q.push(t->left);
                    visited[t->left->val] = true;
                }
                if(t->right && !visited[t->right->val]) {
                    q.push(t->right);
                    visited[t->right->val] = true;
                }
                if(lookup[t] && !visited[lookup[t]->val]) {
                    q.push(lookup[t]);
                    visited[lookup[t]->val] = true;
                }
            }
            k--;
        }
        if(k == 0) {
            while(!q.empty()) {
                TreeNode* t = q.front();
                q.pop();
                if(t->left && !visited[t->left->val]) {
                    res.push_back(t->left->val);
                    visited[t->left->val] = true;
                }
                if(t->right && !visited[t->right->val]) {
                    res.push_back(t->right->val);
                    visited[t->right->val] = true;
                }
                if(lookup[t] && !visited[lookup[t]->val]) {
                    TreeNode *temp = lookup[t];
                    res.push_back(temp->val);
                    visited[temp->val] = true;
                }
            }
        }
        
        return res;    
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == nullptr) {
            return vector<int>{};
        }
        if(K == 0 || !target) {
            if(target)
                return vector<int>{target->val};
            else
            {
                return vector<int>{};
            }
        }
        buildTree(root, nullptr);
        
        return distance(target, K);
    }
private:
    unordered_map<TreeNode*, TreeNode*> lookup;
};