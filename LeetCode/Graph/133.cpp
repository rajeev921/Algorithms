/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//BFS - Breadth First Search

class Solution {
public:
    inline Node* createNode(int v)
    {
        return (new Node(v, {}));
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        Node* copy = createNode(node->val);
        copies[node] = copy;
        
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            for(Node* nd : cur->neighbors)
            {
                if(copies.find(nd)==copies.end())
                {
                    copies[nd] = createNode(nd->val);
                    q.push(nd);
                }
                copies[cur]->neighbors.push_back(copies[nd]);
            }    
        }   
        return copy;
    }
private:
    unordered_map<Node*, Node*> copies;
};

// DFS - Depth First Search   --- It is faster than BFS.
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        
        if(copies.find(node)==copies.end())
        {
            copies[node] = new Node(node->val, {});
            for(Node* nd : node->neighbors)
            {
                copies[node]->neighbors.push_back(cloneGraph(nd));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};