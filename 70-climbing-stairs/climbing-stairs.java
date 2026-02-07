class Solution {
    public int climbStairs(int n) {
        // n=1  -1
        // n=2 - 1,1 or 2
        // n=3 - 1,1,1 or 1,2 or 2,1
        // n=4 - 1,1,1,1 or 1,1,2 or 2,1,1 or 2,2 or 1,2,1

        if (n <= 3) return n;

        // dp[i] - how many steps to reach step i
        int[] dp = new int[n + 1];

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
