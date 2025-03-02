class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n+1,INT_MAX);

        dp[0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                // j==0, means first element in current roww
                if(j==0){
                    dp[j]=dp[j]+triangle[i][j];
                }else if(j==i){ //j==i means last element in current row
                    dp[j]=dp[j-1]+triangle[i][j];
                }else{ //mid element can come from left or right diagonal
                    dp[j]=min(dp[j],dp[j-1]) + triangle[i][j];
                }
            }
        }
        // dp[i] --> indicated min path to reach the current index in current row
        // there are different path to reach the last row, hence we take min of all of them
        return *min_element(dp.begin(),dp.end());
    }
};