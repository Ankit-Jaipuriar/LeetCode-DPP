class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();

        vector<int> in(n,0);

        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                in[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto g:adj[curr]){
                in[g]--;
                if(in[g]==0){
                q.push(g);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};