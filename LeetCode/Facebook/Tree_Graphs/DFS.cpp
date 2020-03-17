void DFS(Node* t) {
        
        stack<Node*> st;
        st.push(t);
        vector<bool> visited(100, false);
        visited[t->val]= true;
        
        while(!st.empty()) {
            Node* nd = st.top();
            cout << nd->val << "  ";
            st.pop();
            for(Node* nd : nd->neighbors) {
                if(!visited[nd->val]) {
                   st.push(nd);
                   visited[nd->val] = true; 
                }
            }
        }
    }