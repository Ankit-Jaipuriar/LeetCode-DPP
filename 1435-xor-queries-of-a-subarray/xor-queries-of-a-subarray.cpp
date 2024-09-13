class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            int L = queries[i][0];
            int R = queries[i][1];
            int val = 0;
            for (int j = L; j <= R; j++) {
                val ^= arr[j];
            }
            ans.push_back(val);
        }
        return ans;
    }
};
