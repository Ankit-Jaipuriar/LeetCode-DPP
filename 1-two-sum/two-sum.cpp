class Solution {
public:
    int search(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (nums[m] == k) {
                return m;
            } else if (nums[m] > k) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        for (int i = 0; i < n; i++) {
            int x = target - nums[i];
            int idx = search(temp, x);
            if (idx != -1) {
                for (int j = 0; j < n; j++) {
                    if (temp[idx] == nums[j] && j != i) {
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
