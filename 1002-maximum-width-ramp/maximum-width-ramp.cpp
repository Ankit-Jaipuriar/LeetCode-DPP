class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int idx = v[0].second;

        for(int i = 1; i < v.size(); i++) {
            int cIdx = v[i].second;
            ans = max(ans, cIdx - idx);
            idx = min(idx, cIdx);
        }
        return ans;
    }
};