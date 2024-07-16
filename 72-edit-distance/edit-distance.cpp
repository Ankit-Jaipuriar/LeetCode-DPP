class Solution {
public:
    int solve(int i,int j,int n, int m, string s1, string s2, vector<vector<int>>&dp){
        if(i==n && j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            if(i+1<=n && j+1<=m){
                return solve(i+1,j+1,n,m,s1,s2,dp);
            }
        }
        int ans = 1e9;
        if(j+1<=m) ans = min(ans,solve(i,j+1,n,m,s1,s2,dp)+1); //insert
        if(i+1<=n) ans = min(ans,solve(i+1,j,n,m,s1,s2,dp)+1); //erase
        if(i+1<=n && j+1<=m) ans = min(ans, solve(i+1,j+1,n,m,s1,s2,dp)+1); //replace
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,word1,word2,dp);
    }
};