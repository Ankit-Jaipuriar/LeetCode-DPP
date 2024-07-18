class Solution {
public:
    vector<vector<int>> ans;    
    void helper(vector<int>& candidates, int target, int curr_sum, int i, vector<int>& temp) {
        if (curr_sum > target) {
            return;
        }
    if (i == candidates.size()) {
        if (curr_sum == target) {
                ans.push_back(temp);
             }
            return;
        }

        curr_sum += candidates[i];
        temp.push_back(candidates[i]);
        helper(candidates, target, curr_sum, i + 1, temp);
        curr_sum -= candidates[i];
        temp.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        helper(candidates, target, curr_sum, i + 1, temp);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0, temp);
        return ans;
    }
};
