class Solution {
public:
    int pivotInd(vector<int>& nums){
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0]){
                s = mid+1;
            }else{
                e = mid;
            }
           mid = s + (e-s)/2; 
        }
        return s;
    }
    int BinarySearch(vector<int>& nums, int s,int e , int target){
        int mid = s+ (e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }else if(target<nums[mid]){
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s+ (e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = pivotInd(nums);
        int ans;
        if(target>=nums[p] && target<=nums[n-1]){
            ans = BinarySearch(nums, p, n-1,target);
        }else{
            ans = BinarySearch(nums, 0 , p-1, target);
        }
        return ans;
    }
};