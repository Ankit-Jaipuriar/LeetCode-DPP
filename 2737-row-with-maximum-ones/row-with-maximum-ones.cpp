class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans(2);
        int maxi = 0;
        int cnt=-1;
        int idx=0;
        for(int i=0;i<m;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
                if(cnt>maxi){
                    maxi=cnt;
                    idx=i;
                }
        }
        ans[0]=idx;
        ans[1]=maxi;
        return ans;
    }
};