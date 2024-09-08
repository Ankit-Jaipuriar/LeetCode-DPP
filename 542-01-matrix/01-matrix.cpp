class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0) mat[i][j] = n+m;
            }
        }
        //left top
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0){
                if(j>0) mat[i][j] = min(mat[i][j], mat[i][j-1]+1); //left
                if(i>0) mat[i][j] = min(mat[i][j],mat[i-1][j]+1); //top
            }
            }
        }
        // right bottom
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]!=0){
                    if(j<m-1) mat[i][j] = min(mat[i][j],mat[i][j+1]+1); //right
                    if(i<n-1) mat[i][j] = min(mat[i][j], mat[i+1][j]+1); //bottom
                }
            }
        }
        return mat;
    }
};