[2192. All Ancestors of a Node in a Directed Acyclic Graph](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)

## Question

You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges    


## Logic

Parent -> Child (TLE)

Child -> Parent (Accepted)



## Solution

```cpp
class Solution {
public:
    unordered_map<int, set<int>> me;
    set<int> dfs(map<int, vector<int>> &graph, int start) {
        if (me.find(start) != me.end()) {
            return me[start];
        }
        set<int> parents;
        for (int i = 0; i < graph[start].size(); i++) {
            set<int> temp;
            parents.insert(graph[start][i]);
            temp = dfs(graph, graph[start][i]);
            for (auto x : temp) {
                parents.insert(x);
            }
        }
        me[start] = parents;
        return parents;
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;
        vector<vector<int>> sol;

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            set<int> temp = dfs(graph, i);
            sol.push_back({temp.begin(), temp.end()});
        }
        
        
        return sol;
    }
};
```

## Complexity

 __Time Complexity__: O(total_edges * total_edges), because we are using Depth first search. Actully it will be less as we are also using memorization.
 
 __Space Complexity__: O(total_edges * total_edges), becuase we are storing solution to return them also we are making graph in inverted manner so that will also add O(total_edges * total_edges). So 2 * O(total_edges * total_edges) = O(total_edges * total_edges)
