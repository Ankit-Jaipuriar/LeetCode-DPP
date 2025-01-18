class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
    bool isSafe(int i,int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    grid[i][j]='0';
                    q.push({i,j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for(auto d: dir){
                            int newx = x+d[0];
                            int newy = y+d[1];

                            if(isSafe(newx,newy,m,n) && grid[newx][newy]=='1'){
                                grid[newx][newy]='0';
                                q.push({newx,newy});
                            }
                        }
                    }
                }
            }
        }
        return count;
        
    }
};