class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool flag = false;  
        for(int i = 0, j = 1; j < nums.size(); j++) {
            int first = nums[i], second = nums[j];
            if ((first % 2 == 0 && second % 2 == 0) || (first % 2 != 0 && second % 2 != 0)) {
                return false;  
            }
            i++;  
        }
        return true;  
    }
};
