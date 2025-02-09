class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp_max(n + 1, 0), dp_min(n + 1, 0);
        dp_max[1] = nums[0]; 
        dp_min[1] = nums[0];
        int maxp = nums[0];

        for (int i = 2; i <= n; i++) {  
            int num = nums[i - 1];  
            dp_max[i] = max(num, max(dp_max[i - 1] * num, dp_min[i - 1] * num));
            dp_min[i] = min(num, min(dp_max[i - 1] * num, dp_min[i - 1] * num));
            maxp = max(maxp, dp_max[i]);
        }
        return maxp;
    }
};
