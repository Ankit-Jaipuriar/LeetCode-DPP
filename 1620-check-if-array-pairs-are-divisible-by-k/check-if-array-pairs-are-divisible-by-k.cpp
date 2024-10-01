class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainder_count(k, 0);
        for (int num : arr) {
            remainder_count[((num % k) + k) % k]++;
        }
        
        if (remainder_count[0] % 2 != 0) return false; 
        for (int i = 1; i <= k / 2; i++) {
            if (remainder_count[i] != remainder_count[k - i]) return false;
        }
        
        return true;
    }
};
