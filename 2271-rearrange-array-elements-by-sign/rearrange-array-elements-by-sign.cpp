class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);

        int i=0,j=1;
        for(auto x:nums){
            if(x>=0){
                result[i]=x;
                i+=2;
            }else{
                result[j]=x;
                j+=2;
            }
        }
        return result;
    }
};