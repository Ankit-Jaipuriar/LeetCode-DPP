class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target, int curr_sum, vector<int>& temp, int i){
        if(curr_sum>target){
            return;
        }
        if(i==candidates.size()){
            if(curr_sum==target){
                ans.push_back(temp);
            }
            return;
        }
        curr_sum+=candidates[i];
        temp.push_back(candidates[i]);
        helper(candidates, target, curr_sum, temp,i);
        curr_sum-=candidates[i];
        temp.pop_back();
        helper(candidates, target, curr_sum, temp,i+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates,target, 0, temp, 0);
        return ans;
    }
};