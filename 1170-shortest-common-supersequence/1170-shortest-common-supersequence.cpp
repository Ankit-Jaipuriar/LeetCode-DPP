class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
       int n=str1.size(),m=str2.size();

        // --> To find shortest supersequence
        // 1. Find the common letter means use LCS and fill dp table
        // 2. Then backtrack to find the remaining letter using dp table
        // To find only length of SCS, just add n+m - Len(LCS)

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int i=n,j=m;
        string ans="";
        while(i>0 && j>0){
            // if character matches then add only one time
            // move diagonal as we came from there in LCS
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--,j--;
            }else if(dp[i][j-1]>=dp[i-1][j]){   //if left one is > than up then we have to include str2
                ans+=str2[j-1];
                j--;
            }else{
                ans+=str1[i-1];
                i--;
            }
        }

        while(i>0) ans+=str1[i-1], i--; //it may happen that we reached i=0, but j != 0 add remaining character.
        while(j>0) ans+=str2[j-1], j--; //vice versa

        // we started from bottom to top, hence we to reverse to get org string

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
