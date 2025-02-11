class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp; 
        unordered_map<int, int> reverse_map; 
        
        for (auto& op : operations) {
            int old_val = op[0], new_val = op[1];
            if (reverse_map.count(old_val)) {
                int prev_val = reverse_map[old_val];
                mp[prev_val] = new_val; 
                reverse_map.erase(old_val); 
                reverse_map[new_val] = prev_val; 
            } else {
                mp[old_val] = new_val;
                reverse_map[new_val] = old_val;
            }
        }

        for (int& num : nums) {
            if (mp.count(num)) {
                num = mp[num];
            }
        }

        return nums;
    }
};
