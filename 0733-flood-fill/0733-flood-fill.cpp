class Solution {
public:
    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

    bool isSafe(int r, int c, vector<vector<int>>& image){
        return r<image.size() && r>=0 &&  c<image[0].size() && c>=0;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int color){
        image[sr][sc]=color;
        for(auto d:dir){
            int newr = sr+d[0];
            int newc = sc+d[1];

            if(isSafe(newr, newc,image) && image[newr][newc]==oldColor){
                dfs(image,newr,newc,oldColor,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};