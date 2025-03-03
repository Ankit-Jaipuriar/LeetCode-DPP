class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, 0)));
        
        for(int i = 0; i < n; i++) {
            for(int u = 0; u <= k; u++) {
                dp[i][i][u] = 1;
            }
        }

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for(int u = 0; u <= k; u++) {
                    if (s[i] != s[j]) {
                        int diff = abs(s[i] - s[j]);
                        int cost = min(diff, 26 - diff);
                        if (u - cost >= 0) {
                            dp[i][j][u] = max({dp[i + 1][j][u], dp[i][j - 1][u], 2 + dp[i + 1][j - 1][u - cost]});  
                        } else {
                            dp[i][j][u] = max(dp[i + 1][j][u], dp[i][j - 1][u]);
                        }
                    } else {
                        dp[i][j][u] = 2 + dp[i + 1][j - 1][u];
                    }
                }
            }
        }
        return dp[0][n-1][k];
    }
};
