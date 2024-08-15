class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        for(auto edge:edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int curr = q.front();
            if(curr==destination){
                return true;
            }
            q.pop();
            for(auto neighbour:graph[curr]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
        return false;
    }
};