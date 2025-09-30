class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dx = {-1,1,0,0}; 
        vector<int> dy = {0,0,-1,1};
        vector<vector<int>> street = {
            {},
            {2,3}, {0,1}, {2,1}, {3,1}, {2,0}, {3,0}
        };

        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            if(x==m-1 && y==n-1) return true;

            for(int dir: street[grid[x][y]]){
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny]) continue;

                int opposite = (dir^1); 
                for(int d: street[grid[nx][ny]]){
                    if(d==opposite){
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return false;
    }
};
