class Solution {
public:
    const int MOD=1e9+7;
    vector<vector<int>> dir = {{0,-1},{-1,0},{1,0},{0,1}};

    bool isSafe(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j,int n,int m){
        if(dp[i][j]!=-1) return dp[i][j];

        int count=1;
        for(auto d:dir){
            int newi=i+d[0];
            int newj=j+d[1];

            if(isSafe(newi,newj,n,m) && grid[newi][newj]>grid[i][j]){
                count=(count+dfs(grid,dp,newi,newj,n,m))%MOD;
            }
        }
        return dp[i][j]=count;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        long long result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result=(result+dfs(grid,dp,i,j,n,m))%MOD;
            }
        }
    return result;
    }
};