class Solution {
public:
    int helper(int i, int n, vector<int>& arr, int k, vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len*maxi) + helper(j+1,n,arr,k,dp);
            maxAns = max(maxAns,sum);
        }
        return dp[i]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return helper(0,n,arr,k,dp);
    }
};