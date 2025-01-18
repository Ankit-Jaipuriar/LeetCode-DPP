class Solution {
public:
    vector<vector<int>> dir = {{0,-1}, {0,1}, {-1,0}, {1,0}};
    bool isSafe(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n; 
    }

    void dfs(vector<vector<int>>& grid, int m,int n,int i,int j){
        grid[i][j]=0;

        for(auto d:dir){
            int newx = i+d[0];
            int newy = j+d[1];

            if(isSafe(newx,newy,m,n) && grid[newx][newy]==1){
                dfs(grid,m,n,newx,newy);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m =  grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]==1){
                       dfs(grid,m,n,i,j);
                    }
                }
            }
        }


        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};