class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;  // Base case: Single element

        int inc_len = 1, dec_len = 1, max_len = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc_len++;         // Increase increasing sequence length
                dec_len = 1;       // Reset decreasing sequence length
            } 
            else if (nums[i] < nums[i - 1]) {
                dec_len++;         // Increase decreasing sequence length
                inc_len = 1;       // Reset increasing sequence length
            } 
            else {
                inc_len = 1;       // Reset both when elements are equal
                dec_len = 1;
            }

            max_len = max(max_len, max(inc_len, dec_len));
        }

        return max_len;
    }
};
