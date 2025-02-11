class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp;  // Stores next greater elements

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Maintain a decreasing stack: Pop smaller elements
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            // If stack is empty, no greater element
            mp[nums2[i]] = s.empty() ? -1 : s.top();

            // Push current element onto stack
            s.push(nums2[i]);
        }

        // Find results for nums1
        vector<int> ans;
        for (auto num : nums1) {
            ans.push_back(mp[num]);  // Get stored next greater element
        }

        return ans;
    }
};
