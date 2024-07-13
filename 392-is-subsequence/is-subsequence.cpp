class Solution {
public:
    bool solve(const string &str1, const string &str2, int m, int n, vector<vector<int>> &memo) {
        if (m == 0) return true; // All characters of str1 matched
        if (n == 0) return false; // str2 is exhausted

        if (memo[m][n] != -1) return memo[m][n];

        if (str1[m - 1] == str2[n - 1]) {
            memo[m][n] = solve(str1, str2, m - 1, n - 1, memo);
        } else {
            memo[m][n] = solve(str1, str2, m, n - 1, memo);
        }

        return memo[m][n];
    }

    bool isSubsequence(string s, string t) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
        return solve(s, t, s.size(), t.size(), memo);
    }
};
