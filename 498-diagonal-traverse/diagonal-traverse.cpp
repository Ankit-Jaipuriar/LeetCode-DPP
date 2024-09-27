class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int count=0,up=1;
        int i=0,j=0;
        vector<int> ans;
        while(count<m*n){
            if(up==1){
                while(i>=0 && j<n){
                    ans.push_back(mat[i][j]);
                    count++;
                if(j==n-1){
                    i++;
                    break;
                }else if(i==0){
                    j++;
                    break;
                }
                i--;
                j++;
                }
                up^=1;
            }else{
                 while(j>=0 && i<m){
                    ans.push_back(mat[i][j]);
                    count++;
                if(i==m-1){
                    j++;
                    break;
                }else if(j==0){
                    i++;
                    break;
                }
                i++;
                j--;
                 }
                up^=1;  
            }
        }
        return ans;
    }
};