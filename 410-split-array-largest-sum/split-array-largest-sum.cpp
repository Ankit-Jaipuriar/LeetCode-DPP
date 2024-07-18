class Solution {
public:
    int count(vector<int>& nums, int mid){
        int cnt = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }else{
                cnt+=1;
                sum = nums[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int splits = count(nums,mid);
            if(splits>k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high+1;
    }
};