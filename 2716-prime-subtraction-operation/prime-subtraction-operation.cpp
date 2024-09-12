class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<bool> isPrime = sieve(1000);
        vector<int> primes;
        for (int i = 2; i <= 1000; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }

        int n = nums.size();
        vector<int> res(n, -1);
        res[n-1] = nums[n-1];

        for (int i = n-2; i >= 0; --i) {
            if (nums[i] < res[i+1]) {
                res[i] = nums[i];
                continue;
            }
            for (auto p : primes) {
                if (p >= nums[i]) {
                    res[i] = nums[i];
                    break;
                }
                if (nums[i] - p < res[i+1]) {
                    res[i] = nums[i] - p;
                    break;
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            if (res[i] <= res[i-1]) return false;
        }
        return true;
    }
};
