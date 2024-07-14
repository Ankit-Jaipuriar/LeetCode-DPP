class Solution {
public:
    int helper(int i, int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        int down = triangle[i][j] + helper(i+1,j,n,triangle,dp);
        int diag = triangle[i][j] + helper(i+1,j+1,n,triangle,dp);
        return dp[i][j]=min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = vector<int>(triangle[i].size(), INT_MIN);
        }
        return helper(0,0,n,triangle,dp);
    }
};