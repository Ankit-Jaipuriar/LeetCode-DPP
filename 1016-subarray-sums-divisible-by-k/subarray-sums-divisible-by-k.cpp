class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;
        int sum=0;
        mp[0]++;
        for(auto i:nums){
            sum+=i;
            if(mp[(sum%k+k)%k]>0){
                count+=mp[(sum%k+k)%k]++;
            }else{
                mp[(sum%k+k)%k]++;
            }
        }
        return count;
    }
};