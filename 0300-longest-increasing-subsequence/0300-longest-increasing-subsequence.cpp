class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //length of LIS starting from index i whose prev index is p
        int n = nums.size();
        vector<int> dp(n,1);
        if(n==1) return 1;
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]+1);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};