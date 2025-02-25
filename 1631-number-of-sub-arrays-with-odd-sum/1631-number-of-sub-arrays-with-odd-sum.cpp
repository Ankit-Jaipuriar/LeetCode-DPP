class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1, 0); // 1-indexed DP array
        int mod = 1e9 + 7;
        long long result = 0;

        // Base case: First element at index 1
        if (arr[0] % 2 == 1) {
            dp[1] = 1;
        } else {
            dp[1] = 0;
        }
        result = dp[1];

        // Traverse array with 1-based indexing
        for (int i = 2; i <= n; i++) {
            if (arr[i - 1] % 2 == 1) {
                if (i > 1) {
                    dp[i] = (1 + (i - 1 - dp[i - 1])) % mod; // Odd flips even prefix sums
                } else {
                    dp[i] = 1;
                }
            } else {
                dp[i] = dp[i - 1]; // Even keeps previous count
            }
            result = (result + dp[i]) % mod;
        }

        return result;
    }
};