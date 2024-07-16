class Solution {
public:
    int solve(int i, int j, string& s1,string& s2, vector<vector<int>>& dp){
        if(i==s1.size()||j==s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans = solve(i+1,j+1,s1,s2,dp)+1;
        }
        ans = max(ans, max(solve(i,j+1,s1,s2,dp),solve(i+1,j,s1,s2,dp)));
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
       int n = s.size();
       string s1 = s;
       reverse(s.begin(),s.end());
       string s2 = s;
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solve(0,0,s1,s2,dp); 
    }
};