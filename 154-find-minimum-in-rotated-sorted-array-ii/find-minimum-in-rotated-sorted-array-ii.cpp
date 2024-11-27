class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            ans = min(ans, nums[mid]);

            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            // Left half is sorted
            else if (nums[mid] >= nums[low]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
