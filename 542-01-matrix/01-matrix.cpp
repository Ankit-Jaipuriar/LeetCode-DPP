class Solution {
public:
    bool isSafe(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // source of bfs -> numbers are 0
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=n+m;
                }
            }
        }
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto curr = q.front();
            int i = curr.first, j=curr.second;
            q.pop();
            for(int k=0;k<4;k++){
                int newi = i+dir[k][0];
                int newj = j+dir[k][1];
                if(isSafe(newi,newj,n,m) && mat[newi][newj]>mat[i][j]+1){
                    mat[newi][newj]=mat[i][j]+1;
                    q.push({newi,newj});
                }
            }
        }
        return mat;
    }
};