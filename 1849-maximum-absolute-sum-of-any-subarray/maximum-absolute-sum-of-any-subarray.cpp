class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, currentMax = 0, currentMin = 0;
        
        for (int num : nums) {
            currentMax = max(currentMax + num, num);
            maxSum = max(maxSum, currentMax);
            
            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
        }
        
        return max(maxSum, abs(minSum));
    }
};
