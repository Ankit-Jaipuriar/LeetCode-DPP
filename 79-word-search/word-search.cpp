class Solution {
public:
    bool flag;

    void solve(int i, int j, int idx, vector<vector<bool>>&visited,vector<vector<char>>&board, string &word){
        if(idx==word.length()){
            flag=true;
            return;
        }
        int n = board.size();
        int m = board[0].size();
        if(i<0 or i>=n or j<0 or j>=m or visited[i][j]){
            return;
        }
        if(word[idx]==board[i][j]){
            visited[i][j]=true;
            solve(i+1,j,idx+1,visited,board,word);
            solve(i-1,j,idx+1,visited,board,word);
            solve(i,j+1,idx+1,visited,board,word);
            solve(i,j-1,idx+1,visited,board,word);
            visited[i][j]=false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,0,visited,board,word);
            }
        }
        return flag;
    }
};