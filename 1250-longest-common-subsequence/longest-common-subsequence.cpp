class Solution {
public:
    int solve(int i, int j, string& str1, string& str2,vector<vector<int>>& dp) {
        if (i == str1.size() || j == str2.size()) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if (str1[i] == str2[j]) {
            return 1 + solve(i + 1, j + 1, str1, str2,dp);
        } else {
            return dp[i][j]=max(solve(i + 1, j, str1, str2,dp), solve(i, j + 1, str1, str2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(),m=text2.size();
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1));
        dp[n][m]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if (text1[i] == text2[j]) {
                         dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
                }
        }   
        return dp[0][0];
    }
};
