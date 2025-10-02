class Solution {
public:
    int K;
    vector<vector<pair<int,int>>> g;

    pair<long long,long long> dfs(int u, int parent) {
        vector<long long> contrib;
        long long base = 0;

        for (auto [v,w] : g[u]) {
            if (v == parent) continue;
            auto [skip, take] = dfs(v,u);
            base += skip;
            contrib.push_back(take + w - skip);
        }

        sort(contrib.begin(), contrib.end(), greater<>());
        long long withParent = base, withoutParent = base;

        for (int i=0; i<min(K,(int)contrib.size()); i++)
            if (contrib[i] > 0) withoutParent += contrib[i];
        for (int i=0; i<min(K-1,(int)contrib.size()); i++)
            if (contrib[i] > 0) withParent += contrib[i];

        return {withoutParent, withParent};
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size()+1;
        K = k;
        g.assign(n,{});
        for (auto &e: edges) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        auto [skip,take] = dfs(0,-1);
        return skip; 
    }
};
