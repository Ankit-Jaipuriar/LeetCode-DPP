class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int source, int destination, vector<bool>& vis){
        if(source==destination) return true;
        vis[source]=true;
        for(auto neighbor:graph[source]){
            if(!vis[neighbor] && dfs(graph,neighbor,destination,vis)) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n,false);
        for(auto edge:edges){
            int u = edge[0],v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return dfs(graph,source,destination,vis);
    }
};