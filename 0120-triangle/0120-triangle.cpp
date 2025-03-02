class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = triangle[0][0]; // Initialize with the top element of the triangle

        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) { // Traverse from right to left to avoid overwriting
                if (j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                } else if (j == i) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                }
            }
        }
        return *min_element(dp.begin(), dp.begin() + n);
    }
};
