class Solution {
public:
    int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for (int ind = i; ind <= j; ++ind) {
            int cost = cuts[j + 1] - cuts[i - 1] + helper(i, ind - 1, cuts, dp) + helper(ind + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        return helper(1, cuts.size() - 2, cuts, dp);
    }
};
