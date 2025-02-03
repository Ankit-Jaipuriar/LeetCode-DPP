class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int>> ans(n, vector<int>(n));
        
        // for len1;
        for(int i=0;i<n;i++){
            ans[i][i]=nums[i];
        }
        // for len2;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                ans[i][j] = (ans[i][j-1] ^ ans[i+1][j]);
            }
        }

        // Now calculate dp;
        vector<vector<int>> dp(n, vector<int>(n));

        // for len1
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
        }

        // for len2;

        for(int i=0;i<n-1;i++){
            dp[i][i+1] = max(ans[i][i+1], max(dp[i][i], dp[i+1][i+1]));
        }

        //len 3..n

        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;

                dp[i][j] = max(ans[i][j],max(dp[i][j-1], dp[i+1][j]));
            }
        }
        vector<int> q;

        for(int k=0; k<queries.size(); k++){
            int i = queries[k][0];
            int j = queries[k][1];

            q.push_back(dp[i][j]);
        } 

        return q;
    }
};