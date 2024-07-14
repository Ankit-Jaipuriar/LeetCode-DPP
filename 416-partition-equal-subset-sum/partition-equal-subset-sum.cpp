class Solution {
public:
    bool subset(int n, int sum, int i, int curr_sum,vector<int>&nums, vector<vector<int>>&dp){
        if(i==n){
            return false;
        }
        if(dp[i][curr_sum]!=-1) return dp[i][curr_sum];
        if(curr_sum==sum) return true;
        int a = subset(n,sum,i+1,curr_sum+nums[i],nums,dp);
        int b = subset(n,sum,i+1,curr_sum,nums,dp);
        dp[i][curr_sum] = a||b;
        return dp[i][curr_sum];
    }
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      int sum = accumulate(nums.begin(),nums.end(),0);
      vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
      if(sum%2!=0) return false;
      return subset(n,sum/2,0,0,nums,dp);
    }
};