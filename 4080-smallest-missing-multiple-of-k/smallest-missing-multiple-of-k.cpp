class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        int t;
        for(int i=1;i<=101;i++){
            t=k*i;
            if(mp.find(t)==mp.end()){
                break;
            }
        }
        return t;
    }
};