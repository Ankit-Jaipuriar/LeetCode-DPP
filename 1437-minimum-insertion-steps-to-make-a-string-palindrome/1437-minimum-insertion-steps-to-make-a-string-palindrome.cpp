class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }

        //len >= 2

        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;

                if(s[i]==s[j]){
                    dp[i][j] = 2 + (i+1<=j-1 ? dp[i+1][j-1]:0);
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        int l = dp[0][n-1];
        return n-l;
    }
};