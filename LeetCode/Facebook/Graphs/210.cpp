vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses,vector<int>());
        vector<int>rank(numCourses,0);
        for(const auto&p:prerequisites){
            graph[p[1]].emplace_back(p[0]);
            ++rank[p[0]];
        }
        queue<int>q;
        unordered_set<int>visited;
        vector<int>res;
        for(int i=0;i<rank.size();++i) if(!rank[i]) q.emplace(i);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            if(!visited.insert(f).second)    continue;
            res.emplace_back(f);
            for(int i:graph[f]) if(!--rank[i])  q.emplace(i);
        }
        if(accumulate(begin(rank),end(rank),0)) return {};
        return res;
    }

==================================================================================================

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());
        
        for(auto pre:prerequisites)
        {
            graph[pre.second].push_back(pre.first);
            indegree[pre.first]++;
        }
        queue<int> que;
        for(int i=0;i<indegree.size();i++)
            if(indegree[i]==0)
                que.push(i);
                
        while(!que.empty())
        {
            int u = que.front();que.pop();
            res.push_back(u);
            for(auto v:graph[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    que.push(v);
            }
        }
        if(res.size()==numCourses)
            return res;
        else
            return vector<int>();
    }
};

==================================================================================================
// BFS

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        vector<int> order;
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    order.push_back(j);
                    break;
                }
            }
            if (j == numCourses) {
                return {};
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }        
        return order;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};

// DFS

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> order;
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i, order)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int neigh : g[node]) {
            if (!acyclic(g, todo, done, neigh, order)) {
                return false;
            }
        }
        order.push_back(node);
        todo[node] = false;
        return true;
    }
};


================================================================================================

Topological Sort is Easy -- The General Template
*
What we need ?
1. HashMap<Node, Indegree> inDegree: A in-degree map, which record each nodes in-degree.
2. HashMap<Node, List<Node>children> topoMap: A topo-map which record the Node's children

What we do ?
1. Init: Init the two HashMaps.
2. Build Map: Put the child into parent's list ; Increase child's in-degree by 1.
3. Find Node with 0 in-degree: Iterate the inDegree map, find the Node has 0 inDegree. (If none, there must be a circle)
4. Decrease the children's inDegree by 1: Decrease step3's children's inDegree by 1.
5. Remove this Node: Remove step3's Node from inDegree. Break current iteration.
6. Do 3-5 until inDegree is Empty: Use a while loop

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // Topological sort
        // Edge case
        if(numCourses <= 0) return new int[0];
        
        //1. Init Map
        HashMap<Integer, Integer> inDegree = new HashMap<>();
        HashMap<Integer, List<Integer>> topoMap = new HashMap<>();
        for(int i = 0; i < numCourses; i++) {
            inDegree.put(i, 0);
            topoMap.put(i, new ArrayList<Integer>());
        }
        
        //2. Build Map
        for(int[] pair : prerequisites) {
            int curCourse = pair[0], preCourse = pair[1];
            topoMap.get(preCourse).add(curCourse);  // put the child into it's parent's list
            inDegree.put(curCourse, inDegree.get(curCourse) + 1); // increase child inDegree by 1
        }
        //3. find course with 0 indegree, minus one to its children's indegree, until all indegree is 0
        int[] res = new int[numCourses];
        int base = 0;
        while(!inDegree.isEmpty()) {
            boolean flag = false;   // use to check whether there is cycle
            for(int key : inDegree.keySet()) {  // find nodes with 0 indegree
                if(inDegree.get(key) == 0) {
                    res[base ++] = key;
                    List<Integer> children = topoMap.get(key);  // get the node's children, and minus their inDegree
                    for(int child : children) 
                        inDegree.put(child, inDegree.get(child) - 1);
                    inDegree.remove(key);      // remove the current node with 0 degree and start over
                    flag = true;
                    break;
                }
            }
            if(!flag)  // there is a circle --> All Indegree are not 0
                return new int[0];
        }
        return res;
    }
}

================================================================================================

