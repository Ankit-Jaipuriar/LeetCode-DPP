class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        set<int> s;
        for(int f:friends){
            s.insert(f);
        }
        for(int o:order){
            if(s.find(o)!=s.end()){
                ans.push_back(o);
            }
        }
        return ans;
    }
};