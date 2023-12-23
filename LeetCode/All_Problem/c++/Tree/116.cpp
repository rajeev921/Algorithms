/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if((root==nullptr) || (root->left==nullptr && root->right==nullptr)) {
            return root;
        }
        if(root->left) {
            root->left->next = root->right;
        }
        connect(root->left);
        if(root->right && root->next) {
            root->right->next = root->next->left;
        }
        connect(root->right);
        return root;
    }
};

void connect(TreeLinkNode *root) {
        if (!root) return; //Edge Case
        
        queue<TreeLinkNode*> q;
        
        //Trick: Push NULL to maintain depth information
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeLinkNode* curr = q.front(); q.pop();

            if (curr==NULL) 
            {
                if (q.size() > 0) q.push(NULL);
            }
            else
            {
                curr->next = q.front();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }

}
