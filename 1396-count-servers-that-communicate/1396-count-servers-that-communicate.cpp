class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& count) {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;
        count++;

        // Check all servers in the same row
        for (int col = 0; col < m; col++) {
            if (grid[i][col] == 1 && !visited[i][col]) {
                dfs(i, col, grid, visited, count);
            }
        }

        // Check all servers in the same column
        for (int row = 0; row < n; row++) {
            if (grid[row][j] == 1 && !visited[row][j]) {
                dfs(row, j, grid, visited, count);
            }
        }
    }

    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int totalServers = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int count = 0;
                    dfs(i, j, grid, visited, count);
                    if (count > 1) {
                        totalServers += count;
                    }
                }
            }
        }

        return totalServers;
    }
};
