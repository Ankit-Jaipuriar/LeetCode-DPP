class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
        int ans;
        for(auto j:freq){
            if(j.second>=2){
                ans = j.first;
            }
        }
        return ans;
    }
};