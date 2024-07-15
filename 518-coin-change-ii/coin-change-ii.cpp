class Solution {
public:
    // int count=0;
    int solve(int i,int curr_sum,int k,vector<int>& coins,vector<vector<int>>& dp){
        if(i==coins.size()){
            if(curr_sum==k){
            return 1;
            }else{
                return 0;
            }
        }
           if(dp[i][curr_sum]!=-1){
            return dp[i][curr_sum];
        }
        int a = solve(i,curr_sum+coins[i],k,coins,dp);
        int b = solve(i+1,curr_sum,k,coins,dp);
        return dp[i][curr_sum]=(a+b);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int n = coins.size(); 
        // Initialize base case
        dp[n][amount] = 1;
        for (int i = 0; i < amount; i++) {
            dp[n][i] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = amount; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                if (j + coins[i] <= amount) {
                    dp[i][j] += dp[i][j + coins[i]];
                }
            }
        }
        return dp[0][0];
    }
};