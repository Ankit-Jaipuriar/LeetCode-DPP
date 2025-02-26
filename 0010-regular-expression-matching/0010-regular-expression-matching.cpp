class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n + 1][m + 1];  
        memset(dp, false, sizeof(dp));
        dp[0][0] = true; 

        // Initialize dp for cases where the pattern contains '*' (matches zero characters)
        for (int j = 2; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {

                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];  
    }
};
