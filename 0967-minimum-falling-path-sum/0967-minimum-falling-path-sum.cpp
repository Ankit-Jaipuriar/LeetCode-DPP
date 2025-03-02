class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(matrix[0]); 

        for (int i = 1; i < n; i++) {
            vector<int> temp = dp; 
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[j] = min(temp[j], temp[j + 1]) + matrix[i][j];
                } else if (j == n - 1) {
                    dp[j] = min(temp[j], temp[j - 1]) + matrix[i][j];
                } else {
                    dp[j] = min({temp[j - 1], temp[j], temp[j + 1]}) + matrix[i][j];
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
