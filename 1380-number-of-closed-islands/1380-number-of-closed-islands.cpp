class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};

    bool isSafe(int i,int j, int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m){
        grid[i][j]=1;

        for(auto d:dir){
            int newx=d[0]+i;
            int newy=d[1]+j;

            if(isSafe(newx,newy,n,m) && grid[newx][newy]==0){
                dfs(newx,newy,grid,n,m);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        // traverse boundary lands to mark it and its nbr as unsafe
        // travers on remaining zeroes and run dfs on it 
        // increase the count and count connected components of lands.

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==0){
                        dfs(i,j,grid,n,m);
                    }
                }
            }
        }
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return count;
    }
};