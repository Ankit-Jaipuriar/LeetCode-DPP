class Solution {
public:
    int total_cost;
    void dfs(int node, int parent, vector<vector<pair<int,int>>>& graph, vector<int>& vis, vector<int>& cost_of_rev_of_node, int curr_depth,vector<int>& depth){
        vis[node]=1;
        depth[node]=curr_depth;

        for(pair<int, int> child : graph[node]){
            if(!vis[child.first]){
                cost_of_rev_of_node[child.first]=cost_of_rev_of_node[node]+child.second; // depth of child = depth of parent + 1
                total_cost+=child.second; // adding cost of going to that child
                dfs(child.first, node, graph, vis, cost_of_rev_of_node, curr_depth+1, depth); // now child becomes node and node becomes parent
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);
        int sz=edges.size();
        int root=-1;
        for(int i=0;i<sz;i++){
            int x=edges[i][0],y=edges[i][1];
            graph[x].push_back({y,0}); // org dir cost=0
            graph[y].push_back({x,1}); // reversed dir cost=1
            if(graph[x].size()==1){
                root=x;
            }
            if(graph[y].size()==1){
                root=y;
            }
        }

        total_cost=0; // total cost to reach every node from a root node
        int parent=-1;
        int curr_depth=0;
        vector<int> depth(n,0); // depth of each node from parent
        vector<int> cost_of_rev_of_node(n,0); // store cost of every node from root
        vector<int> vis(n,0);
        
        dfs(root, parent, graph, vis, cost_of_rev_of_node, curr_depth, depth);

        vector<int> ans(n, 0); 
        ans[root]=total_cost;
        for(int i=0; i<n; i++){ 
            if(i==root) continue;
            int i_to_root = depth[i]-cost_of_rev_of_node[i];
            int val = total_cost - cost_of_rev_of_node[i];
            int res = val+i_to_root;
            ans[i]=res;
        }

        return ans; 
    }
};
