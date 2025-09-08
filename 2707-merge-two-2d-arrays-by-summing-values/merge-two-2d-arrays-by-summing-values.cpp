class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();

        while(i!=n && j!=m){
            int x=nums1[i][0];
            int y=nums2[j][0];
            int val1=nums1[i][1];
            int val2=nums2[j][1];
            if(x==y){
                result.push_back({x,val1+val2});
                i++;
                j++;
            }else{
                if(x<y){
                    result.push_back({x,val1});
                    i++;
                }else{
                    result.push_back({y,val2});
                    j++;
                }
            }
        }
        while(i<n){
            result.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }
        while(j<m){
            result.push_back({nums2[j][0],nums2[j][1]});
            j++;
        }

        return result;
    }
};