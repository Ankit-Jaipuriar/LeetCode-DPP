class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> basis;
        for(int num:nums){
            for(int b:basis){
                num = min(num,num^b);
            }

            if(num>0){
                basis.push_back(num);
                sort(basis.begin(),basis.end(),greater<int>());
            }
        }
        int max_xor=0;
        for(int b:basis){
            if((max_xor ^ b)>max_xor){
                max_xor = max_xor ^ b;
            }
        }
        return max_xor;

    }
};