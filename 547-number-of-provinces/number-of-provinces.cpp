class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int curr, vector<bool>& vis){
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            if(isConnected[curr][i] && !vis[i]){
                vis[i]=true;
                dfs(isConnected, i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(isConnected,i,vis);
            }
        }
        return count;
    }
};