class Solution {
public:
    int solve(vector<int>& nums,int i,int prev, vector<vector<int>>& dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int ans = 0;
        if(prev==-1 || nums[i]>nums[prev]){
            ans = 1+solve(nums,i+1,i,dp);
        }
            ans = max(ans, solve(nums,i+1,prev,dp));
            return dp[i][prev+1]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1)); 
        return solve(nums,0,-1,dp);
    }
};