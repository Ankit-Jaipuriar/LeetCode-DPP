class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i] --> minimum cost to reach ith index
        cost.push_back(0);  
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;  // base case
        dp[1] = cost[0];  
        dp[2] = cost[1];

        for (int i = 3; i <= n; i++) {
            dp[i] = min(dp[i - 2] + cost[i - 1], dp[i - 1] + cost[i - 1]);
        }
        
        return dp[n]; 
    }
};
