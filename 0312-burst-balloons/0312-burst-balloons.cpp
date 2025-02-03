class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();

        vector<int> arr(n+2);
        arr[0]=1;
        for(int i=1;i<=n;i++){
            arr[i]=nums[i-1];
        }
        arr[n+1]=1;
        for(auto i:arr){
            cout<<i<<" ";
        }

        vector<vector<int>> dp(n+2, vector<int>(n+2));

        // len 1
        int i=1;
        while(i<=n){
            dp[i][i]=arr[i-1]*arr[i]*arr[i+1];
            i++;
        }

        // len2 .... n
        int len=2;
        while(len<=n){
            i=1;
            int j=i+len-1;
            while(j<=n){
                int k=i;
                int maxi = INT_MIN;
                while(k<=j){
                int possibility=arr[i-1]*arr[k]*arr[j+1];
                if(k-1>=i){
                    possibility+=dp[i][k-1];
                }
                if(k+1<=j){
                    possibility+=dp[k+1][j];

                }
                maxi = max(maxi,possibility);
                k++;
                }
                dp[i][j]=maxi;

                i++;j++;
            }


            len++;
        }

        return dp[1][n];
    }
};