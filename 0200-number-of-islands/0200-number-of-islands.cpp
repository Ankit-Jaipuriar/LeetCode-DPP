class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
    bool isSafe(int i,int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j){
        grid[i][j]='0';
        for(auto d:dir){
            int newr = i + d[0];
            int newc = j + d[1];
            if(isSafe(newr,newc,m,n) && grid[newr][newc]=='1'){
                dfs(grid,m,n,newr,newc);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,m,n,i,j);
                }
            }
        }
        return count;
        
    }
};