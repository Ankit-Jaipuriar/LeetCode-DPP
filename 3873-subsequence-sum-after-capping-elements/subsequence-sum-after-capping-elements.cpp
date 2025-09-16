class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(std::vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> answer(n, false);
        vector<int> counts(n + 1, 0);
        for (int num : nums) {
            counts[num]++;
        }
        
        vector<int> count_ge(n + 2, 0);
        for (int i = n; i >= 1; --i) {
            count_ge[i] = count_ge[i + 1] + counts[i];
        }
        vector<bool> dp(k + 1, false);
        dp[0] = true;
        
        for (int x = 1; x <= n; ++x) {
            for (int s = 0; s <= k; ++s) {
                if (dp[s]) {
                    int remainder = k - s;
                    if (remainder >= 0 && remainder % x == 0) {
                        int num_x_needed = remainder / x;
                        if (num_x_needed <= count_ge[x]) {
                            answer[x - 1] = true;
                            break;
                        }
                    }
                }
            }
            
  
            if (counts[x] > 0) {
                for (int i = 0; i < counts[x]; ++i) {
                    for (int s = k; s >= x; --s) {
                        if (dp[s - x]) {
                            dp[s] = true;
                        }
                    }
                }
            }
        }
        
        return answer;
    }
};