class Solution {
public:
    vector<bool> isPrime(int r) {
        vector<bool> prime(r + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= r; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= r; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2, -1);
        vector<int> temp;
        vector<bool> prime = isPrime(right);
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                temp.push_back(i);
            }
        }

        if (temp.size() < 2) {
            return ans;
        }

        int minDiff = INT_MAX;
        for (int i = 1; i < temp.size(); i++) {
            int diff = temp[i] - temp[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                ans[0] = temp[i - 1];
                ans[1] = temp[i];
            }
        }

        return ans;
    }
};
