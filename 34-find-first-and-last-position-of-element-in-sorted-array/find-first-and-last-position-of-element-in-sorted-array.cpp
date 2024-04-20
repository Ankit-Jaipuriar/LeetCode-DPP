class Solution {
public:
    int firstOccur(vector<int>& nums, int target){
        int s = 0;
        int e  = nums.size()-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(nums[mid]==target){
                ans = mid;
                e = mid - 1;
            }else if(nums[mid]>target){
                e = mid - 1;
            }else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    int lastOccur(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(nums[mid]==target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid]>target){
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s+ (e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
    int a = firstOccur(nums, target);
    int b = lastOccur(nums, target);
    vector<int>  res;
    res.push_back(a);
    res.push_back(b);
    return res;
    }
};