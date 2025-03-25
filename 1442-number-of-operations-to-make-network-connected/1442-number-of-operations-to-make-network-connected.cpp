class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        
        // If we don't have at least (n - 1) edges, it's impossible
        if (edges < n - 1) return -1;

        // Create adjacency list
        vector<vector<int>> adj(n);
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        // Find number of connected components
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }

        // Extra edges available = total edges - minimum required edges (n-1)
        int extraEdges = edges - (n - components);

        // If we have enough extra edges to connect components, return (components - 1)
        return (extraEdges >= (components - 1)) ? (components - 1) : -1;
    }
};
