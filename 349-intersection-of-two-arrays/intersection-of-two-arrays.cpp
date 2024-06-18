class Solution {
public:
    set<int> ans;
    void solve(vector<int>&arr,int k){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int m = (s+e)/2;
            if(arr[m]==k){
                ans.insert(arr[m]);
                break;
            }else if(k<arr[m]){
                e = m-1;
            }else{
                s = m+1;
            }
        }
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums2.size();i++){
        solve(nums1, nums2[i]);
        }
        vector<int> vc(ans.begin(), ans.end());
        return vc;
    }
};