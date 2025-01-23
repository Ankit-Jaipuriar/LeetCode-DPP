class Solution {
public:
    int parent[62501];
    int rnk[62501];

    void make(int i) {
        parent[i] = i;
        rnk[i] = 0;
    }

    int find(int v) {
        if (parent[v] == v) {
            return parent[v];
        } else {
            return parent[v] = find(parent[v]);
        }
    }

    void unite(int a, int b) {
        int root1 = find(a);
        int root2 = find(b);

        if (root1 != root2) {
            if (rnk[root1] > rnk[root2]) {
                parent[root2] = root1;
            } else if (rnk[root2] > rnk[root1]) {
                parent[root1] = root2;
            } else {
                parent[root1] = root2;
                rnk[root2]++;
            }
        }
    }

    int toIndex(int i, int j, int m) {
        return i * m + j;
    }

    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n * m; i++) {
            make(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // Union all servers in the same row
                    for (int k = j + 1; k < m; k++) {
                        if (grid[i][k] == 1) {
                            unite(toIndex(i, j, m), toIndex(i, k, m));
                        }
                    }
                    // Union all servers in the same column
                    for (int k = i + 1; k < n; k++) {
                        if (grid[k][j] == 1) {
                            unite(toIndex(i, j, m), toIndex(k, j, m));
                        }
                    }
                }
            }
        }

        // Count servers that communicate
        vector<int> serverCount(n * m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    serverCount[find(toIndex(i, j, m))]++;
                }
            }
        }

        int totalServers = 0;
        for (int i = 0; i < n * m; i++) {
            if (serverCount[i] > 1) {
                totalServers += serverCount[i];
            }
        }

        return totalServers;
    }
};
