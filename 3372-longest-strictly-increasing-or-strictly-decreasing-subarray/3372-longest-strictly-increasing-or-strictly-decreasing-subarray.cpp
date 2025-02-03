class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp1(n,vector<int>(n));
        vector<vector<int>> dp2(n,vector<int>(n));
        int maxLength = 1;

        // for len1;
        for(int i=0;i<n;i++){
            dp1[i][i]=1;
            dp2[i][i]=1;
        }

        // for len2;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                dp1[i][i+1]=2;
                dp2[i][i+1]=1;
            }else if(nums[i]>nums[i+1]){
                dp2[i][i+1]=2;
                dp1[i][i+1]=1;
            } else {
                dp1[i][i+1] = 1;
                dp2[i][i+1] = 1;
            }
            maxLength = max(maxLength, max(dp1[i][i+1], dp2[i][i+1]));
        }
    
        // for len3,4,...n;
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(nums[j-1] < nums[j]){
                    dp1[i][j] = dp1[i][j-1] + 1;
                    dp2[i][j] = 1;
                } else if(nums[j-1] > nums[j]){
                    dp2[i][j] = dp2[i][j-1] + 1;
                    dp1[i][j] = 1;
                } else {
                    dp1[i][j] = 1;
                    dp2[i][j] = 1;
                }
                maxLength = max(maxLength, max(dp1[i][j], dp2[i][j]));
            }
        }

        return maxLength;
    }
};
