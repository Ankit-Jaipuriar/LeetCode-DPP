class Solution {
public:
    // int count=0;
    int solve(int i,int curr_sum,int k,vector<int>& coins,vector<vector<int>>& dp){
        if(curr_sum==k){
            return 1;
        } 
         if (curr_sum > k || i >= coins.size()) {
            return 0;
        }
           if(dp[i][curr_sum]!=-1){
            return dp[i][curr_sum];
        }
        int a = solve(i,curr_sum+coins[i],k,coins,dp);
        int b = solve(i+1,curr_sum,k,coins,dp);
        return dp[i][curr_sum]=(a+b);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(0,0,amount,coins,dp);
    }
};