class Solution {
public:
    long long maxProduct(vector<int>& nums) {
    int max_val = 0;
    if (!nums.empty()) {
        max_val = *std::max_element(nums.begin(), nums.end());
    }

    // Determine the size of our dp table.
    // If max_val is 0, we only need 1 bit. Otherwise, find the number of bits.
    int bits = (max_val == 0) ? 1 : floor(log2(max_val)) + 1;
    int dp_size = 1 << bits; // This is equivalent to 2^bits

    std::vector<int> dp(dp_size, 0);

    // --- Part 2: Initialization ---
    // For each number in our input, set dp[num] = num.
    for (int num : nums) {
        dp[num] = num;
    }

    // --- Part 3: Propagation ---
    // Loop through each bit position.
    for (int i = 0; i < bits; ++i) {
        // Loop through every possible mask.
        for (int mask = 0; mask < dp_size; ++mask) {
            // If the i-th bit of the mask is ON...
            if ((mask >> i) & 1) {
                // ...update the mask's value with its submask's value.
                // The submask is the mask with the i-th bit flipped OFF.
                dp[mask] = std::max(dp[mask], dp[mask ^ (1 << i)]);
            }
        }
    }

    // --- Part 4: Find Max Product ---
    long long max_product = 0;
    int all_ones_mask = dp_size - 1;

    // Loop through each original number.
    for (int x : nums) {
        // Calculate the complement mask.
        int complement_mask = all_ones_mask ^ x;
        
        // Find the best partner using our completed dp table.
        int y = dp[complement_mask];

        // Update the maximum product.
        if (y != 0) { // Ensure a partner was found
            max_product = std::max(max_product, (long long)x * y);
        }
    }

    return max_product;
    }
};
