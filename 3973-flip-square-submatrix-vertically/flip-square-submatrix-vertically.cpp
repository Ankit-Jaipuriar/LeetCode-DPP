class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top=x, bottom=x+k-1;
        while(top<bottom){
            for(int i=y;i<=y+k-1;i++){
                swap(grid[top][i],grid[bottom][i]);
            }
            top++;
            bottom--;
        }
        return grid;
    }
};