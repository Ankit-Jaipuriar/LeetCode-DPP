class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int idx, int n){
        if(idx==n){
            ans.push_back({nums});
            return;
        }

        for(int i=idx;i<n;i++){
            swap(nums[idx], nums[i]); //idx place ==> ith element choice
            solve(nums,idx+1,n);
            swap(nums[idx],nums[i]); //backtracking
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        solve(nums,0,n);
        return ans;
    }
};