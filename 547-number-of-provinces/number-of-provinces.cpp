class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int curr, vector<bool>& visited){
        int n = isConnected.size();
        for(int i=0;i<n;i++){
            if(isConnected[curr][i] && !visited[i]){
                visited[i]=true;
                dfs(isConnected,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, i,visited);
            }
        }
        return count;
    }
};