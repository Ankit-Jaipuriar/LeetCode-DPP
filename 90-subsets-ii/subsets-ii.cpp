class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int>& temp, int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        helper(nums, temp, i+1);
        temp.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        helper(nums, temp, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
         sort(nums.begin(), nums.end());
        helper(nums, temp, 0);
        return ans;
    }
};