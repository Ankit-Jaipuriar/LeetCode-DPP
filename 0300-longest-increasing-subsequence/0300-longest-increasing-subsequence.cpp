class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[1]=1; //longest increasing subsequence till index i including i
        
        int i=2;
        while(i<=n){
            dp[i]=1;
            int j=i-1;
            int curr=nums[i-1];
            while(j>=1){
                if(curr>nums[j-1]){
                dp[i]=max(dp[i],1+dp[j]);
                }
                j--;
            }
            i++;
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};