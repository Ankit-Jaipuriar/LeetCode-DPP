class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int src, int dest, vector<bool>& visited){
        if(src==dest){
            return true;
        }
        visited[src]=true;
        for(auto neighbour:graph[src]){
            if(!visited[neighbour] && dfs(graph,neighbour,dest,visited)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        for(auto edge:edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return dfs(graph, source, destination, visited);
    }
};