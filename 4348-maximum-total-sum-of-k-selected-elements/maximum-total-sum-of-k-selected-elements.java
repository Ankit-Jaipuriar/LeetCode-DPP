class Solution {
    public long maxSum(int[] nums, int k, int mul) {
        int n=nums.length;
        Arrays.sort(nums);
        long sum=0;
        for(int i=n-1;i>=n-k;i--){
            if(mul==0) sum+=nums[i];
            else sum+=(long)nums[i]*mul;
            if(mul!=0) mul--;
        }
        return sum;
    }
}