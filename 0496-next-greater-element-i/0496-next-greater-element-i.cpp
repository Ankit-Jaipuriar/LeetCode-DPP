class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        s.push(INT_MAX);
        int n = nums2.size();
        vector<int> ans(n);
        unordered_map<int, int> nextGreater; // Map to store next greater elements

        for (int i = n - 1; i >= 0; i--) {
            int curr = nums2[i];
            while (s.top() <= curr) {
                s.pop();
            }
            if (s.top() == INT_MAX) {
                nextGreater[curr] = -1;
            } else {
                nextGreater[curr] = s.top();
            }
            s.push(curr);
        }

        // Prepare result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        return result;
    }
};
