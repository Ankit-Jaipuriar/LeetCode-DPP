class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
       vector<vector<vector<long long>>> dp(n/2, vector<vector<long long>>(3, vector<long long>(3, LLONG_MAX)));

       for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i!=j){
                dp[0][i][j]=cost[0][i] + cost[n-1][j];
            }
        }
       }

        for(int row=1;row<n/2;row++){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i==j) continue;

                    long long minPrev = LLONG_MAX;

                    for(int i1=0;i1<3;i1++){
                        for(int j1=0;j1<3;j1++){
                            if(i1!=i && j1!=j){
                            minPrev = min(minPrev, dp[row-1][i1][j1]);
                            }
                        }
                    }

                    dp[row][i][j] = minPrev + cost[row][i] + cost[n-row-1][j];
                }
            }
        }

        long long res = LLONG_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i!=j){
                    res = min(res,dp[n/2-1][i][j]);
                }
            }
        }
        return res;

    }
};