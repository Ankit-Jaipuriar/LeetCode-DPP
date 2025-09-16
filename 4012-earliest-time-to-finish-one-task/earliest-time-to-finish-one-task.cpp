class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans=INT_MAX;
        for(auto t:tasks){
            int finish=t[0]+t[1];
            ans=min(ans,finish);
        }
    return ans;
    }
};