class Solution {
public:
   // queen can move in 8 directions
    bool isSafe(vector<string>& temp, int row,int col, int n){
        //horizontal
        for(int j=0;j<n;j++){
            if(temp[row][j]=='Q') return false;
        }

        //vertical
        for(int i=0;i<n;i++){
            if(temp[i][col]=='Q') return false;
        }

        //diagonally
        //left
        for(int i=row,j=col;i>=0 && j>=0; i--,j-- ){
             if(temp[i][j]=='Q') return false;
        }

        //right diagonal
        for(int i=row,j=col;i>=0 && j<n; i--,j++ ){
             if(temp[i][j]=='Q') return false;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& temp, int row,int n){
        if(row==n){
            ans.push_back({temp});
            return;
        }

        for(int j=0;j<n;j++){
            if(isSafe(temp,row,j,n)){
                temp[row][j]='Q';
                solve(ans,temp,row+1,n);
                temp[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.')) ;
        solve(ans,temp,0,n);
        return ans;
    }
};