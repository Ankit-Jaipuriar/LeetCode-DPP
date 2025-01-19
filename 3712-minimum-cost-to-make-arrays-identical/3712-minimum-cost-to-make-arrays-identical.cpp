class Solution {
public:
    bool isAscending(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }
    bool isDescending(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans = 0;
        if(arr==brr){
            return 0;
        }
        long long ans3=0;
        for(int i=0;i<arr.size();i++){
            ans3+=abs(arr[i]-brr[i]);
        }
        bool a = isAscending(arr) || isDescending(arr);
        bool b = isAscending(brr) || isDescending(brr);
        long long ans2 = 0;
        if (a || b) {
            for (int i = 0; i < arr.size(); i++) {
                ans2 += abs(arr[i] - brr[i]);
            }
        }
            ans += k; 
            sort(arr.begin(), arr.end());
            sort(brr.begin(), brr.end());
            for (int i = 0; i < arr.size(); i++) {
                ans += abs(arr[i] - brr[i]);
        }
        if(ans2!=0){
        long long x = min(ans2,ans3);
        return min(ans,x);
        }else{
            return min(ans,ans3);
        }
    }
};
