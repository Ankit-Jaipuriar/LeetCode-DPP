class Solution {
public:
    int solve(int n, int m, int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if (i == n - 1 && j == m - 1) {
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = INT_MAX, down = INT_MAX;
        
        if (i + 1 < n) {
            down = grid[i][j] + solve(n, m, i + 1, j, grid,dp);
        }
        if (j + 1 < m) {
            right = grid[i][j] + solve(n, m, i, j + 1, grid,dp);
        }
        
        return dp[i][j]=min(right, down);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n, m, 0, 0, grid,dp);
    }
};
