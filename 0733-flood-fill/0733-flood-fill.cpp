class Solution {
public:
    bool isSafe(int r,int c, vector<vector<int>>& image){
        return r>=0 && r<image.size() && c>=0 && c<image[0].size();
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        queue<pair<int,int>> q;
        int oldColor = image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
               q.pop();
            for(auto d:dir){
                int newr = r+d[0];
                int newc = c+d[1];

                if(isSafe(newr,newc,image) && image[newr][newc]==oldColor){
                    q.push({newr,newc});
                    image[newr][newc]=color;
                }
            }
        }
        return image;
    }
};