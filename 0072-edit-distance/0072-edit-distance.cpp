class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        dp[0][0] = 0;
	    for(int i = 1; i <= n; i++) dp[i][0] = i;       
	    for(int j = 1; j <= m; j++) dp[0][j] = j;  
        int i=1;
        while(i<=n){
            int j=1;
            while(j<=m){
                if(word1[i-1]!=word2[j-1]){
                    dp[i][j] = min(1+dp[i][j-1],min(1+dp[i-1][j], 1+dp[i-1][j-1]));
                }else{
                    dp[i][j]=dp[i-1][j-1];
                }
                j++;
            }
            i++;
        }
        return dp[n][m];
    }
};