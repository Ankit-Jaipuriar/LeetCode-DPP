class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    
    void solve(vector<int>& nums, int idx, int n, vector<int> temp) {
        if (idx == n) {
            sort(temp.begin(), temp.end()); // Sort to handle duplicates
            s.insert(temp);
            return;
        }
        
        // Include the current element
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, n, temp);
        
        // Exclude the current element
        temp.pop_back();
        solve(nums, idx + 1, n, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(nums, 0, n, temp);
        ans.assign(s.begin(), s.end());
        return ans;
    }
};
