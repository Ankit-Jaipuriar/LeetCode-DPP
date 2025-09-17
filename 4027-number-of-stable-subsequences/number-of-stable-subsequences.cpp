class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {

        int MOD = 1e9 + 7;
        long long one_odd=0;
        long long two_odd=0;
        long long one_even=0;
        long long two_even=0;

        for(int num:nums){
            if(num%2==0){
                long long new_one_even = 1  + one_odd + two_odd;
                long long new_two_even = one_even;

                one_even= (one_even+new_one_even)%MOD;
                two_even= (two_even+new_two_even)%MOD;
            }else{
                long long new_one_odd = 1  + one_even + two_even;
                long long new_two_odd = one_odd;

                one_odd= (one_odd+new_one_odd)%MOD;
                two_odd= (two_odd+new_two_odd)%MOD;
            }
        }
        long long total = (one_even+two_even+one_odd+two_odd)%MOD;
        return (int)total;
    }
};