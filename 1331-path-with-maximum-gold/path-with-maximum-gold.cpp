class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1}; 
    
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return 0;
        }
        
        int currentGold = grid[i][j];
        grid[i][j] = 0; 
        
        int maxGold = 0;
        for (int k = 0; k < 4; k++) {
            int newi = i + x[k];
            int newj = j + y[k];
            maxGold = max(maxGold, solve(newi, newj, n, m, grid));
        }
        
        grid[i][j] = currentGold; 
        return currentGold + maxGold;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    maxi = max(maxi, solve(i, j, n, m, grid));
                }
            }
        }
        
        return maxi;
    }
};
