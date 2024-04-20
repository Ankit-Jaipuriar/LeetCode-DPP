class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2;
        if(nums[s]<nums[e]){
            return nums[s];
        }
        while(s<e){
            if(nums[mid]>=nums[0]){
                s  = mid+1;
            }else{
                e = mid;
            }
             mid = s+(e-s)/2;
        }
        return nums[s];
    }
};