class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN, sum = nums[0];

        for (int i = 0, j = 1; j < n; j++) {
            if (nums[j] > nums[j - 1]) {
                sum += nums[j];  
            } else {
                maxi = max(maxi, sum); 
                sum = nums[j]; 
            }
        }

        return max(maxi, sum);  
    }
};
