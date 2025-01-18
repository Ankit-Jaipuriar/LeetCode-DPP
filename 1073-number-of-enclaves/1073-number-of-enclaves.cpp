class Solution {
public:
    bool isSafe(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n; 
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m =  grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        grid[i][j]=0;
                    }
                }
            }
        }

        vector<vector<int>> dir = {{0,-1}, {0,1}, {-1,0}, {1,0}};

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto d:dir){
                    int newx = x+d[0];
                    int newy = y+d[1];

                    if(isSafe(newx,newy,m,n) && grid[newx][newy]==1){
                        grid[newx][newy]=0;
                        q.push({newx,newy});
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