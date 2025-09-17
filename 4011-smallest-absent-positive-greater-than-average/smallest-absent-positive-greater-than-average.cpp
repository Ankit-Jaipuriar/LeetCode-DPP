class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double sum=0;
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int num:nums){
            mp[num]++;
            maxi = max(maxi,num);
            sum+=num;
        }
        int n=nums.size();
        double avg = sum/double(n);
        int temp = floor(avg)+1;
         int ans = max(1, temp);

        while(true){
            if(mp.find(ans)==mp.end()){
                return ans;
            }
            ans++;
        }
        return ans;

    }
};