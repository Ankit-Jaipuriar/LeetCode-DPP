class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};

    bool isSafe(int i, int j, int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    void dfs(int i,int j, vector<vector<int>>& grid, int n,int m){
        grid[i][j]=0;

        for(auto d:dir){
            int newx=i+d[0];
            int newy=j+d[1];

            if(isSafe(newx,newy,n,m) && grid[newx][newy]==1){
                dfs(newx,newy,grid,n,m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        // we should not go to boundary
        // traverse boundary and run dfs having land cell
        // mark all its nbrs as unsafe so that we can not got unsafe cell in future
        //count the number of 1s left after this operation
        //It is the answer

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1 ){
                    if(grid[i][j]==1){
                        dfs(i,j,grid,n,m);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};