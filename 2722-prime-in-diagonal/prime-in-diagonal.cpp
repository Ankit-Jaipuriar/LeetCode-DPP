class Solution {
public:
    vector<bool> sieve(int maxVal) {
        vector<bool> prime(maxVal + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= maxVal; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int maxVal = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxVal = max(maxVal, nums[i][j]);
            }
        }
        vector<bool> prime = sieve(maxVal);
        vector<int> v;

        for (int i = 0; i < m; i++) {
            v.push_back(nums[i][i]);
        }
        for (int i = 0; i < m; i++) {
            v.push_back(nums[i][n - 1 - i]);
        }

        int maxi = 0;
        for (int i = 0; i < v.size(); i++) {
            if (prime[v[i]]) {
                maxi = max(maxi, v[i]);
            }
        }
        return maxi;
    }
};
