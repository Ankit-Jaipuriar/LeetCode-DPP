class Solution {
public:
bool dfs(vector<vector<int>>& graph,vector<int>& vis,int curr, int color){
    vis[curr]=color;
    for(int neighbor:graph[curr]){
        if(vis[neighbor]==-1){
            if(dfs(graph,vis,neighbor,1-color)==false){
                return false;
            }
        }else if(vis[neighbor]==color){
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
     int n = graph.size();
     vector<int> vis(n,-1);
     for(int i=0;i<n;i++){
        if(vis[i]==-1 && dfs(graph,vis,i,0)==false){
            return false;
        }
     }
     return true;
    }
};