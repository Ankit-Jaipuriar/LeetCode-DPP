class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;

        while(i<j){
            if(nums[i]%2>nums[j]%2){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }else if(nums[i]%2==0){
                i++;
            }else{
                j--;
            }
        }
        return nums;
    }
};