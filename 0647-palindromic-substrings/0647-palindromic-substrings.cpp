class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int count = 0;  

        // for len 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            count++;  
        }

        // for len 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                count++; 
            }
        }

        // for len 3 to n
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    count++;  
                }
            }
        }

        return count;  
    }
};
