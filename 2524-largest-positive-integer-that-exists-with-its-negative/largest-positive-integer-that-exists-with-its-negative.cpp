
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int maxPairs = 0;
        int s = 0;
        int e = nums.size() - 1;
        
        while (s < e) {
            if (nums[s] + nums[e] == 0) {
                mp[nums[s]]++;
                mp[nums[e]]++;
                s++;
                e--;
            } else if (nums[s] + nums[e] < 0) {
                s++;
            } else {
                e--;
            }
        }
        
        for (auto it : mp) {
            maxPairs = max(maxPairs, it.first);
        }
        if(maxPairs==0){
            return -1;
        }
        return maxPairs;
    }
};
