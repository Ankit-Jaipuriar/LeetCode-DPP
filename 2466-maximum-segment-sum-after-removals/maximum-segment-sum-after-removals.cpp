class DSU {
public:
    vector<int> parent;
    vector<long long> sums;

    DSU(int n, const vector<int>& nums) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
        
        sums.resize(n);
        for (int i = 0; i < n; ++i) {
            sums[i] = nums[i];
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_j] = root_i;
            sums[root_i] += sums[root_j];
        }
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();

        DSU dsu(n, nums);
        vector<long long> answer(n);
        vector<bool> active(n, false);
        long long currentMaxSum = 0;
        for (int i = n - 1; i >= 0; --i) {

            answer[i] = currentMaxSum;
            
            int idx = removeQueries[i];
            active[idx] = true;
            if (idx > 0 && active[idx - 1]) {
                dsu.unite(idx, idx - 1);
            }
            if (idx < n - 1 && active[idx + 1]) {
                dsu.unite(idx, idx + 1);
            }
            int root = dsu.find(idx);
            currentMaxSum = max(currentMaxSum, dsu.sums[root]);
        }
        
        return answer;
    }
};
