class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max_val=0;
        if(!nums.empty()){
            max_val = *max_element(nums.begin(),nums.end());
        }

        int bits = (max_val==0) ? 1 : floor(log2(max_val))+1;
        int dp_size=1<<bits;

        vector<int> dp(dp_size,0);

        for(int num:nums){
            dp[num]=num;
        }

        for(int i=0;i<bits;i++){
            for(int mask=0;mask<dp_size;mask++){
                if((mask>>i)&1){
                    dp[mask]=max(dp[mask], dp[mask ^ (1<<i)]);
                }
            }
        }

        long long max_product=0;
        int all_ones_mask=dp_size-1;

        for(int x:nums){
            int complement_mask = all_ones_mask ^ x;

            int y=dp[complement_mask];
            if(y!=0){
                max_product = max(max_product,(long long)x*y);
            }
        }
        return max_product;
    }
};
