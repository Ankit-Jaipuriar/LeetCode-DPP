class Solution {
public:
    int binsearch(vector<int>& arr,int target) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (arr[mid] == target) {
                ans = mid;
                break;
            } if(arr[s]<=arr[mid]){ 
            if(arr[s]<=target && arr[mid]>target){
                e = mid-1;
                }else{
                    s = mid+1;
                }
            }else{
                if(arr[e]>=target && arr[mid]<target){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int ans = binsearch(nums,target);
        return ans;
    }
    };