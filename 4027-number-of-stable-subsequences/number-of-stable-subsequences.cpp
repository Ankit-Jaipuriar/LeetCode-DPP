class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {

        int MOD = 1e9 + 7;

        // Total counts of stable subsequences ending in each state
        long long ends_e1 = 0, ends_e2 = 0, ends_o1 = 0, ends_o2 = 0;

        for (int num : nums) {
            if (num % 2 == 0) { // Number is Even
                // 1. Calculate how many NEW subsequences we can form
                //    - One-evens: The number itself (1) + append to all odd-enders
                long long added_to_e1 = (1 + ends_o1 + ends_o2) % MOD;
                //    - Two-evens: Append to all existing one-even-enders
                long long added_to_e2 = ends_e1;

                // 2. Add these new counts to our running totals
                ends_e1 = (ends_e1 + added_to_e1) % MOD;
                ends_e2 = (ends_e2 + added_to_e2) % MOD;

            } else { // Number is Odd
                // Symmetrical logic for odd numbers
                long long added_to_o1 = (1 + ends_e1 + ends_e2) % MOD;
                long long added_to_o2 = ends_o1;

                ends_o1 = (ends_o1 + added_to_o1) % MOD;
                ends_o2 = (ends_o2 + added_to_o2) % MOD;
            }
        }
        
        // The final answer is the sum of all subsequences we've tracked
        long long total = (ends_e1 + ends_e2 + ends_o1 + ends_o2) % MOD;
        return static_cast<int>(total);
    }
};