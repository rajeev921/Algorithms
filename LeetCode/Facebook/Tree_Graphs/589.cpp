/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == NULL)
        {
            return {};
        }
        else
        {
            result.push_back(root->val);
            for(Node* nd : root->children)
            {
                preorder(nd);
            }
        }
        return result;
    }
    vector<int> result;
};

class Solution2 {
public:
    vector<int> preorder(Node* root) {
        if(root == NULL)
        {
            return {};
        }
        stack<Node*> st;
        vector<int> result;
        
        st.push(root);
        while(!st.empty())
        {
            Node* cur = st.top();
            result.push_back(cur->val);
            st.pop();
            for(int i = cur->children.size()-1; i >= 0; --i)
            {
                st.push(cur->children[i]);
            }
        }
            
        return result;
    }
};
