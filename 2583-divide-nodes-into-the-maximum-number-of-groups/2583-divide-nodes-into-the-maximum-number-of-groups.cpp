
class Solution {
public:
    int parent[1001];
    int rnk[1001];

    void make(int i) {
        parent[i] = i;
        rnk[i] = 0;
    }

    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]); 
        }
        return parent[v];
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (rnk[rootA] > rnk[rootB]) {
                parent[rootB] = rootA;
            } else if (rnk[rootA] < rnk[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rnk[rootA]++;
            }
        }
    }

    bool bipartite(vector<int> adj[], vector<int>& color) {
        queue<int> q;
        q.push(1);
        color[1] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (color[it] == -1) {
                    color[it] = 1 - color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    int maxDepth(int start, int n, vector<int> adj[]) {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int node = q.front();
                q.pop();

                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            depth++;
        }

        return depth;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> adj[n + 1];
        vector<int> color(n + 1, -1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if (!bipartite(adj, color)) {
            return -1;
        }
        for (int i = 1; i <= n; i++) {
            make(i);
        }
        for (auto& edge : edges) {
            unite(edge[0], edge[1]);
        }

        map<int, vector<int>> components;
        for (int i = 1; i <= n; i++) {
            int root = find(i);
            components[root].push_back(i);
        }
        int result = 0;
        for (auto& component : components) {
            int maxDepthInComponent = INT_MIN;
            for (int node : component.second) {
                maxDepthInComponent = max(maxDepthInComponent, maxDepth(node, n, adj));
            }
            result += maxDepthInComponent;
        }

        return result;
    }
};
