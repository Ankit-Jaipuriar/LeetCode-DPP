class Solution {
public:
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
