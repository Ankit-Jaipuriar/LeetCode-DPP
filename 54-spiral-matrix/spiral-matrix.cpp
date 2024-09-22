class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        int top=0,bottom=m,left=0,right=n,dir=1;
        vector<int> res;
        while(top<=bottom && left<=right){
            if(dir==1){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                    top++,dir=2;
            }else if(dir==2){
                for(int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                right--,dir=3;
            }else if(dir==3){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--,dir=4;
            }else if(dir==4){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++,dir=1;
            }
        }
        return res;
    }
};