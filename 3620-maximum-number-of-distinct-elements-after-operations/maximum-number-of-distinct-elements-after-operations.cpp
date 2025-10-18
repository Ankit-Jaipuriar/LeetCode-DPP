class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) { 
        sort(nums.begin(), nums.end());
        set<int> s;
        int last = INT_MIN;

        for (int i = 0; i < (int)nums.size(); i++) {
            int low = nums[i] - k;
            int high = nums[i] + k;
            int val = max(low, last + 1);

            if (val <= high) {
                s.insert(val);
                last = val;
            }
        }
        return s.size();
    }
};
