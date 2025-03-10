class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& candidates,vector<int>& temp, int idx, int n, int target){
        if(idx==n || target<0){
            return;
        }

        if(target==0){
            s.insert({temp});
            return;
        }

        temp.push_back(candidates[idx]);
        solve(candidates,temp,idx+1,n,target-candidates[idx]); //single inclusion
        solve(candidates,temp,idx,n,target-candidates[idx]); //mulitple inclusion
        temp.pop_back();
        solve(candidates,temp,idx+1,n,target); //exclude

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,temp,0,candidates.size(),target);
        ans.assign(s.begin(),s.end());
        return ans;
    }
};