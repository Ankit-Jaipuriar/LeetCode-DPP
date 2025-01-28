class Solution {
public:
    int parent[100];
    int rnk[100];

    void make(int i){
        parent[i]=i;
        rnk[i]=0;
    }

    int find(int v){
        if(parent[v]==v){
            return parent[v];
        }
        return parent[v]=find(parent[v]);
    }

    void unite(int a,int b){
        int root1=find(a);
        int root2=find(b);

        if(root1>root2){
            parent[root2]=root1;
        }else if(root2>root1){
            parent[root1]=root2;
        }else{
            parent[root1]=root2;
            rnk[root2]++;
        }
    }

    int toIdx(int i, int j,int m){
        return i*m+j;
    }

    bool isSafe(int i, int j, int n, int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<m*n;i++){
            make(i);
        }

        vector<vector<int>> dir = {{0,-1},{-1,0},{1,0},{0,1}};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                for(auto d:dir){
                    int newi = d[0]+i;
                    int newj = d[1]+j;

                    if(isSafe(newi,newj,n,m) && grid[newi][newj]>0){
                        unite(toIdx(i,j,m), toIdx(newi,newj,m));
                    }
                }
                }
            }
        }

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                int root = find(toIdx(i,j,m));
                mp[root]+=grid[i][j];
                }
            }
        }

        int maxi = 0;

        for(auto p:mp){
            maxi=max(maxi,p.second);
        }
        return maxi;


    }
};