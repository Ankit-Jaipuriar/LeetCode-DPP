class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidate, int target, int curr_sum, vector<int>& temp, int i){
        if(curr_sum>target){
            return;
        }
        if(i==candidate.size()){
            if(curr_sum==target){
            ans.push_back(temp);
            }
            return;
        }
        curr_sum+=candidate[i];
        temp.push_back(candidate[i]);
        helper(candidate, target, curr_sum, temp, i);
        curr_sum-=candidate[i];
        temp.pop_back();
        helper(candidate, target, curr_sum, temp, i+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, target,0, temp, 0);
        return ans;
    }
};