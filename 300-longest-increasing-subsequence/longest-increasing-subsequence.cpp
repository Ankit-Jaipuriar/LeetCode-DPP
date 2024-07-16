class Solution {
public:
    int solve(int i,int prev,vector<int>& nums, vector<vector<int>>&dp){
        if(i==nums.size()){
            return 0;
        }
        int ans=0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1 || nums[i]>nums[prev]){
            ans = 1+solve(i+1,i,nums,dp);
        }
        ans = max(ans,solve(i+1,prev,nums,dp));
        return dp[i][prev+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};