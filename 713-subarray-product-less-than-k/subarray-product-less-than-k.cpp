class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; 
        
        int count = 0;
        int s = 0;
        int prod = 1;
        
        for (int e = 0; e < nums.size(); e++) {
            prod *= nums[e];
            while (prod >= k && s < e) {
                prod /= nums[s];
                s++;
            }
            if (prod < k) {
                count += e - s + 1;
            }
        }
        
        return count;
    }
};
