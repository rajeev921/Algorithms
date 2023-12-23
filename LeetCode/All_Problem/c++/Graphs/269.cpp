/*
eally nice solution! Let me try to explain the code with example in the problem description:

First, build a degree map for each character in all the words:

w:0
r:0
t:0
f:0
e:0

Then build the hashmap by comparing the adjacent words, the first character that is different between two adjacent words reflect the lexicographical order. For example:

 "wrt",
 "wrf",
    first different character is 3rd letter, so t comes before f

 "wrf",
 "er",
    first different character is 1rd letter, so w comes before e

The characters in set come after the key. x->y means letter x comes before letter y. x -> set: y,z,t,w means x comes before all the letters in the set. The final HashMap "map" looks like.

t -> set: f    
w -> set: e
r -> set: t
e -> set: r

and final HashMap "degree" looks like, the number means "how many letters come before the key":

w:0
r:1
t:1
f:1
e:1

Then use Kahn's aglorithm to do topological sort. This is essentially BFS.
https://en.wikipedia.org/wiki/Topological_sorting.
*/


/*			Steps
	STEP 1: Initialize
		for each letter in each word indegree[letter] = 0;

	STEP 2: Build Graph and Record the edge
		for each edge (cur node, nex node) graph.insert(cur, nex)
		for each nex node indegree[nex]++;

	STEP 3: Topological Sort
		use queue, push all nodes which indegree is 0;
		use BFS start to iterate the whole graph.

	STEP 4: Tell if cyclic
		compare the result with indegree if (res.size() == indegree.size());
*/

//space complexity: O(max(V, E)) while degree use O(V) and map uses O(E).
//time complexity: O(max(V, E)). V is the number of nodes and E is edge number in the graph.
// 

class Solution {
public:
	void buildGraph(vector<string>& words, unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& indegree) {
		// 1. Initialize each letter indegree[letter]= 0
		for(auto word : words){
			for(char ch : word){
				indegree[ch] = 0;
			}
		}
        
        int len = words.size();
		
        // 2. build graph and record indegree
		for(int i{}; i < len-1; ++i){
			string cur = words[i];
			string nex = words[i+1];
			int minLen = min(cur.length(), nex.length());
			for(int j{}; j < minLen; ++j){
				char c1 = cur.at(j);
				char c2 = nex.at(j);
				if(c1 != c2){
					unordered_set<char> st; 
					if(graph.find(c1) != graph.end())
						st = graph[c1];
					if(st.find(c2) == st.end()) {
						graph[c1].insert(c2); // build graph
						indegree[c2]++;	// add indegree
					}
					break;
				}
			}
		}

		return;
	}	

	string topologicalSort(unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& indegree) {
		queue<char> q;
		string result;

		for(auto& e : indegree){
			if(e.second == 0)
				q.push(e.first);
		}

		while(!q.empty()){
			char cur = q.front();
			q.pop();
			result += cur;

			if(graph[cur].size() != 0) {
				for(auto& e : graph[cur]) {
					indegree[e]--;
					if(indegree[e] == 0)
						q.push(e);
				}
			}
		}

		return result;
	}

	string alienOrder(vector<string>& words) {
		int len = words.size();

		if(len < 2){
			if(len==1){
				return words[0];
			}
			return "";
		}

		unordered_map<char, int> indegree;
		unordered_map<char, unordered_set<char>> graph;

		buildGraph(words, graph, indegree);
		
		//3. topological sort
		string result = topologicalSort(graph, indegree);

		//4. Check if it is a cycle
		return result.length() == indegree.size() ? result : "";
	}
};