class Solution {
public:

    int bfs(int src, int end, int n,vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        vector<int> level(n,-1);
        level[src]=0;
        while(!q.empty()){
                int curr=q.front();
                q.pop();

                for(auto v:graph[curr]){
                    if(level[v]==-1){
                    q.push(v);
                    level[v]=level[curr]+1;
                    
                    }
                }
            }
            return level[n-1];
        }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);

        for(int i=0;i<n-1;i++){
            graph[i].push_back(i+1);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
                int x = queries[i][0];
                int y = queries[i][1];

                graph[x].push_back(y);
               int a = bfs(0,n-1,n,graph);
                ans.push_back(a);
        }
        return ans;
    }
};