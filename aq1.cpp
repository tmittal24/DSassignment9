class Solution {
public:

    void depthTraversal(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                depthTraversal(it, adj, visited);
            }
        }
    }

    int countComponents(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        int components = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                components++;
                depthTraversal(i, adj, visited);
            }
        }
        return components;
    }
};
