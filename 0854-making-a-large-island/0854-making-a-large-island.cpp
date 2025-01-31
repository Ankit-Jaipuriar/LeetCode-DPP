class Solution {
public:
    static const int MAX_N = 500*500;
    int parent[MAX_N],rnk[MAX_N],size[MAX_N];

    void make(int i){
        parent[i]=i;
        rnk[i]=0;
        size[i]=1;
    }

    int find(int v){
        if(parent[v]==v){
            return v;
        }
        return parent[v]=find(parent[v]);
    }

    void unite(int a, int b) {
        int root1 = find(a);
        int root2 = find(b);

        if (root1 != root2) {
            if (rnk[root1] > rnk[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
            } else if (rnk[root2] > rnk[root1]) {
                parent[root1] = root2;
                size[root2] += size[root1];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
                rnk[root2]++;
            }
        }
    }
    int toIndex(int i, int j, int n){
        return i*n+j;
    }

    bool isSafe(int i, int j, int n){
        return i>=0 && i<n && j>=0 && j<n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n*n;i++){
            make(i);
        }

        vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto d:dir){
                        int newi=d[0]+i;
                        int newj=d[1]+j;
                    if(isSafe(newi,newj,n) && grid[newi][newj]==1){
                        unite(toIndex(i,j,n), toIndex(newi,newj,n));
                    }
                    }
                }
            }
        }

        int maxIsland=0;
        for(int i=0;i<n*n;i++){
            if(parent[i]==i){
                maxIsland = max(maxIsland,size[i]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int newSize=1;
                    unordered_map<int,int> uniqueIsland;

                    for(auto d:dir){
                        int newi=d[0]+i;
                        int newj=d[1]+j;

                        if(isSafe(newi,newj,n) && grid[newi][newj]==1){
                            int root = find(toIndex(newi,newj,n));

                            if(uniqueIsland.insert({root,1}).second){
                                newSize+=size[root];
                            }
                        }
                    }
                    maxIsland=max(maxIsland,newSize);
                }
            }
        }
        return maxIsland;
    }
};