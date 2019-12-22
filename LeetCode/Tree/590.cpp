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
    vector<int> result;
    vector<int> postorder(Node* root) {
        if(root == NULL)
            return {};
        else {
            for(Node* nd : root->children)
            {
                postorder(nd);    
            }
            if(root) {
                result.push_back(root->val);
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> postorder(Node* root) {
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
            for(int i = 0; i < cur->children.size(); ++i)
            {
                st.push(cur->children[i]);
            }
        }
        reverse(result.begin(), result.end());   
        
        return result;
    }
};