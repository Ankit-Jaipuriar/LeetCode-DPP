class Solution {
public:
    vector<int> ans;
    void solve(vector<int>& nums, int target){
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int rem = target-nums[i];
            if(mp.find(rem)!=mp.end()){
                ans.push_back(mp[rem]);
                ans.push_back(i);
            }
            mp[nums[i]]=i;
        }
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        solve(nums,target);
        return ans;
    }
};