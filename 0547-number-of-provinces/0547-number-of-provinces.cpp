class Solution {
public:

    int parent[201];
    int rnk[201];

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
            parent[root2]=root1;
        }else if(rnk[root2]>rnk[root1]){
            parent[root1]=root2;
        }else{
            parent[root1]=root2;
            rnk[root2]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();

        for(int i=0;i<n;i++){
            make(i);
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                if(isConnected[i][j]==1){
                    unite(i,j);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(find(i)==i){
                count++;
            }
        }
        return count;
    }
};