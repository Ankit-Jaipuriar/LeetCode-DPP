class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = nums[i] + solve(nums, i + 2, dp);
        ans = max(ans, solve(nums, i + 1, dp));
        return dp[i] = ans; 
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
