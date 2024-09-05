class Solution {
public:
    int countdigits(int n){
        return floor(log10(n)+1);
    }
    bool canAliceWin(vector<int>& nums) {
        int sum1=0;
        int sum2=0;
        for(int i=0;i<nums.size();i++){
            if(countdigits(nums[i])==1){
                sum1+=nums[i];
            }else{
                sum2+=nums[i];
            }
        }
        if(sum1>sum2 || sum2>sum1){
            return true;
        }
        return false;
    }
};