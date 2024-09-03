class Solution {
public:
int sol(string& A, string& B, int i, int j, vector<vector<int>>& dp) {
    if (i == A.size() || j == B.size()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    } 
    if (A[i] == B[j]) {
        dp[i][j] = 1 + sol(A, B, i + 1, j + 1, dp);
    } else {

        dp[i][j] = max(sol(A, B, i, j + 1, dp), sol(A, B, i + 1, j, dp));
    }   
    return dp[i][j];
}


    int longestCommonSubsequence(string A, string B) {
            int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));  
    return sol(A, B, 0, 0, dp);
}
       
};
