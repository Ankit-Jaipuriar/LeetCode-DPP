class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        // right j++
        // left j--
        // up i--
        // down i++
        vector<vector<int>> grid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = (i*n)+j;
            }
        }
        int i=0,j=0;
        for(int k=0;k<commands.size();k++){
                if(commands[k]=="RIGHT") j++;
                else if(commands[k]=="LEFT") j--;
                else if(commands[k]=="UP") i--;
                else if(commands[k]=="DOWN") i++;
            }
            return grid[i][j];
        }
};