class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
      int n=nums.size();
      unordered_map<int,int> mp;
      vector<int> res;
      for(int i=0;i<n;i++){
        mp[nums[i]]++;
      }

     for(auto p:mp){
        res.push_back(p.first);
    
     }
     sort(res.begin(),res.end(),greater<int>());
     vector<int> ans;
     for(int i=0;i<k && i<res.size();i++){
        ans.push_back(res[i]);
     }
    return ans;
    }
};