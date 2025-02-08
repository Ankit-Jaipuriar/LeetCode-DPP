class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e5);
        dp[0]=0;
        int i=1;
        while(i<=amount){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
            
            i++;
        }
        return dp[amount]==1e5? -1:dp[amount];
    }
};