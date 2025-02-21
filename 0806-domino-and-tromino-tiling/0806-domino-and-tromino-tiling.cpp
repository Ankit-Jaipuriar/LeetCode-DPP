long long int dp[1000+5][5];
int MOD=1e9+7;
class Solution {
public:
    int numTilings(int n) {
    // base case for domino
     dp[1][1]=1;
     dp[2][1]=2;

    // base case for upper tromino
    dp[2][0]=1;
    // base case for down tromino
    dp[2][2]=1; 
    int i=3;

    while(i<=n){
        dp[i][1]=(dp[i-1][1]+dp[i-2][1]+dp[i-1][2]+dp[i-1][0])%MOD; //when we put domino at ith pos

        // upper tromino at i
        dp[i][0]=(dp[i-2][1]+dp[i-1][2])%MOD;

        // down tromino at i
        dp[i][2]=(dp[i-2][1]+dp[i-1][0])%MOD;
    i++;
    }
    return dp[n][1]%MOD;
    }
};