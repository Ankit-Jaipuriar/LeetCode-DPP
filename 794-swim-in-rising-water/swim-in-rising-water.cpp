class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        
        pq.push({grid[0][0], 0, 0});
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        while(!pq.empty()){
            auto [t, x, y] = pq.top(); pq.pop();
            if(vis[x][y]) continue;
            vis[x][y] = true;
            if(x == n-1 && y == n-1) return t; 
            for(int i=0;i<4;i++){
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; 
    }
};