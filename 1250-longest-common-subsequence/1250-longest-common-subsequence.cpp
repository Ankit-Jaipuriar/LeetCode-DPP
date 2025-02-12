class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // dp[i][j]=length of the LCS of text1[0...i-1] and text2[0...j-1]
        int i = 1;
        while (i <= n) {
            int j = 1;
            while (j <= m) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //max[(abcd + ace) or (abcd + ac)]
                    // for b!=a
                    //check for (ab, _ ) and (a , a) max is 1 which is dp[1][1]
                }
                j++;
            }
            i++;
        }

        return dp[n][m];
    }
};
