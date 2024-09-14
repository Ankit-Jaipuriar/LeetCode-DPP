class Solution {
public:
    int solve(int i, vector<int>& nums, int max_val, int length, int& max_length) {
        if (i == nums.size()) {
            return max_length;
        }
        
        if (nums[i] == max_val) {
            length++;
            max_length = max(max_length, length);
        } else {
            length = 0;
        }   
        return solve(i + 1, nums, max_val, length, max_length);
    }
    
    int longestSubarray(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int max_length = 0;
        return solve(0, nums, max_val, 0, max_length);
    }
};
