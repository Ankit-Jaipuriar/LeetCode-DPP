class Solution {
public:
    int parent[1001];
    int rnk[1001];

    void make(int i) {
        parent[i] = i;
        rnk[i] = 0;
    }

    int find(int v) {
        if (parent[v] == v) {
            return parent[v];
        } else {
            return parent[v] = find(parent[v]);
        }
    }

    void unite(int a, int b) {
        int root1 = find(a);
        int root2 = find(b);

        if (rnk[root1] > rnk[root2]) {
            parent[root2] = root1;
        } else if (rnk[root2] > rnk[root1]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            rnk[root1]++;
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent2(n+1,0);
        vector<int> edge1,edge2;

        //conflicting edges --> node with two parent.
        for(int i=0;i<n;i++){
            int u = edges[i][0], v=edges[i][1];
            if(parent[v]!=0){
                edge1 = {parent[v],v};
                edge2 = {u,v};
                edges[i][1]=0;
            }else{
                parent[v]=u;
            }
        }

        for(int i=1;i<=n;i++){
            make(i);
        }

        //detect edge causing cycle
        for(int i=0;i<n;i++){
            if(edges[i][1]==0){
                continue;
            }
            int v = edges[i][0],u=edges[i][1];
            if(find(v)==find(u)){
                if(!edge1.empty()){
                    return edge1;
                }
                return edges[i];
            }else{
                unite(u,v);
            }
        }
    return edge2;
    }
};
