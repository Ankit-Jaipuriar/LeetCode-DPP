class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+1,0);

        int mini=INT_MAX;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            mini=min(mini,prices[i-1]);
            dp[i]=max(dp[i-1],prices[i-1]-mini);
        }
        return dp[n];
    }
};