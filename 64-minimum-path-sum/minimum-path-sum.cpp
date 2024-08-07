class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        dp[n-1][m-1] = grid[n-1][m-1];
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i + 1 < n) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i + 1][j]);
                }
                if (j + 1 < m) {
                    dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j + 1]);
                }
            }
        } 
        return dp[0][0];
    }
};
