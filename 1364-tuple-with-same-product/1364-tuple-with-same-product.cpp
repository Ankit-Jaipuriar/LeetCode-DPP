class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
       unordered_map<int, int> productCount;
    int n = nums.size(), result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int product = nums[i] * nums[j];
            productCount[product]++;
        }
    }

    for (auto& [product, count] : productCount) {
        if (count > 1) {
            result += 4 * count * (count - 1); 
        }
    }

    return result;
    }
};