class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& temp, int target_sum, int curr_sum, int i, int k) {
        if (curr_sum > target_sum) {
            return;
        }
        if (temp.size() == k) {
            if (curr_sum == target_sum) {
                ans.push_back(temp);
            }
            return;
        }
        if(i==nums.size()){
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, temp, target_sum, curr_sum + nums[i], i + 1, k);
        temp.pop_back();
        solve(nums, temp, target_sum, curr_sum, i + 1, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; ++i) {
            nums.push_back(i);
        }
        vector<int> temp;
        solve(nums, temp, n, 0, 0, k);
        return ans;
    }
};
