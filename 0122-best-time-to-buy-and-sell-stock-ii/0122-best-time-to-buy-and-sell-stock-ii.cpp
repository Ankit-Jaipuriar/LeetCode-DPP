class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;            // No stock at the beginning
        dp[0][1] = -prices[0];   // Buying on the first day

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]); 
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]); 

            cout << "Day " << i << ": No Stock = " << dp[i][0] << ", With Stock = " << dp[i][1] << endl;
        }
        return dp[n-1][0]; 
    }
};
