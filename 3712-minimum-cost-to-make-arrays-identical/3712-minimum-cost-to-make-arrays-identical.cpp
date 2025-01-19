class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans = 0;
        if(arr==brr){
            return 0;
        }
        long long ans2=0;
        for(int i=0;i<arr.size();i++){
            ans2+=abs(arr[i]-brr[i]);
        }
            ans += k; 
            sort(arr.begin(), arr.end());
            sort(brr.begin(), brr.end());
            for (int i = 0; i < arr.size(); i++) {
                ans += abs(arr[i] - brr[i]);
        }
        return min(ans,ans2);
    }
};
