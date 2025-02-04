class Solution {
public:
    double dp[105][105];

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();

        // Compute prefix sums for efficient subarray sum calculation
        vector<double> prefixSum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Initialize DP table with small values
        for(int i = 0; i <= 100; i++) {
            for(int j = 0; j <= 100; j++) {
                dp[i][j] = -1e6;
            }
        }

        // Base case: when partition count is 1
        for(int i = 1; i <= n; i++) {
            dp[i][1] = prefixSum[i] / i;
        }

        // DP computation following your pattern
        for(int i = 2; i <= n; i++) {
            int prt = 1;
            while (prt <= k) {
                double v = 0;
                int j = i;
                double sum = prefixSum[i];

                while (j >= 1) {
                    double g = dp[j - 1][prt - 1];

                    if (g > 0) {
                        v = max(v, g + (prefixSum[i] - prefixSum[j - 1]) / (i - (j - 1)));
                    }
                    j--;
                }

                if (v > 0) {
                    dp[i][prt] = v;
                }

                prt++;
            }
        }

        return dp[n][k];
    }
};
