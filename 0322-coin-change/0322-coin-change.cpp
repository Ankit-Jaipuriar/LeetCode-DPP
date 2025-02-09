class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     int n=coins.size();

     vector<int> dp(amount+1,1e5);
     dp[0]=0;

     for (int j = 0; j < n; j++) {  // Iterate over each coin first
    for (int i = coins[j]; i <= amount; i++) {  // Then iterate over possible amounts
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
     }
     return dp[amount]==1e5?-1:dp[amount];
    }
};