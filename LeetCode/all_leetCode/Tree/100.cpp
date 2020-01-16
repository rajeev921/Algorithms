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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL) return false;
        if(p->val == q->val){
            if(isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};

// BFS + queue
bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode*, TreeNode*>> myQueue;
    myQueue.push(pair<TreeNode*, TreeNode*>(p, q));
    while (!myQueue.empty()) {
        p = myQueue.front().first;
        q = myQueue.front().second;
        if(!p ^ !q || (p && q && p->val != q->val))
            break;
        myQueue.pop();
        if(p && q) {
            myQueue.push(pair<TreeNode*, TreeNode*>(p->left, q->left));
            myQueue.push(pair<TreeNode*, TreeNode*>(p->right, q->right));
        }
    }
    return myQueue.empty();
}

// DFS + stack
bool isSameTree3(TreeNode* p, TreeNode* q) {
    stack<pair<TreeNode*, TreeNode* >> myStack;
    myStack.push(pair<TreeNode*, TreeNode*>(p, q));
    while (!myStack.empty()) {
        p = myStack.top().first;
        q = myStack.top().second;
        if (!p ^ !q || (p && q && p->val != q->val))
            break;
        myStack.pop();
        if (p && q) {
            myStack.push(pair<TreeNode*, TreeNode*> (p->right, q->right));
            myStack.push(pair<TreeNode*, TreeNode*> (p->left, q->left));
        }
    }
    return myStack.empty();
}