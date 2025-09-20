class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        long long total = 0;
        stack<int> s; 

        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                int mid = s.top(); 
                s.pop();

                if (!s.empty()) {
                    int left = s.top();
                    if (min(nums[left], nums[i]) > nums[mid]) {
                        total++;
                    }
                }
            }
            s.push(i);
        }

        return total;
    }
};
