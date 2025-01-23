class Solution {
public:
    int parent[201]; // Parent array for Union-Find
    int rnk[201];    // Rank array for Union-Find

    // Initialize Union-Find structure
    void make(int i) {
        parent[i] = i;  // Each city is initially its own parent
        rnk[i] = 0;     // Rank is 0 for all cities
    }

    // Find the root of the set to which i belongs
    int find(int i) {
        if (parent[i] == i) {
            return i;  // City is its own parent (root of the set)
        } else {
            return parent[i] = find(parent[i]); // Path compression
        }
    }

    // Union the sets containing a and b
    void unite(int a, int b) {
        int rootA = find(a);  // Find root of city a
        int rootB = find(b);  // Find root of city b

        if (rootA != rootB) {
            // Union by rank: attach the smaller tree to the larger one
            if (rnk[rootA] < rnk[rootB]) {
                parent[rootA] = rootB;
            } else if (rnk[rootB] < rnk[rootA]) {
                parent[rootB] = rootA;
            } else {
                parent[rootB] = rootA;
                rnk[rootA]++;
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of cities

        // Initialize Union-Find for all cities
        for (int i = 0; i < n; i++) {
            make(i);
        }

        // Process the adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // Only check each pair once
                if (isConnected[i][j] == 1) {  // If cities i and j are connected
                    unite(i, j);  // Union the cities
                }
            }
        }

        // Count the number of unique provinces
        int numProv = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {  // Each unique root represents a province
                numProv++;
            }
        }

        return numProv;
    }
};
