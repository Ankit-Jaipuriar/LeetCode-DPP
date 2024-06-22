class Solution {
public:
vector<vector<int>> ans;
    void solve(vector<int>& nums, int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(nums,i+1);
            //backtrack
            swap(nums[i],nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};