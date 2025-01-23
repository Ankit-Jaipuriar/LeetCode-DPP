class Solution {
public:

    int parent[1001];
    int rnk[1001];

    void make(int i){
        parent[i]=i;
        rnk[i]=0;
    }

    int find(int v){
        if(parent[v]==v){
            return parent[v];
        }else{
            return parent[v]=find(parent[v]);
        }
    }

    void unite(int a, int b){
        int root1=find(a);
        int root2=find(b);

        if(rnk[root1]>rnk[root2]){
            parent[root1]=root2;
        }else if(rnk[root2]>rnk[root1]){
            parent[root2]=root1;
        }else{
            parent[root2]=root1;
            rnk[root1]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        for(int i=0;i<n;i++){
            make(i);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
                if(find(edges[i][0])!=find(edges[i][1])){
                    unite(edges[i][0],edges[i][1]);
                }else{
                    res.push_back(edges[i][0]);
                    res.push_back(edges[i][1]);
                }
            }
        return res;
    }
};