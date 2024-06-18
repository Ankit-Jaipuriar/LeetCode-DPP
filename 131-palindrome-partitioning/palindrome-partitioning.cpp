class Solution {
public:

    void func(string s, vector<string>v, vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(v);
            return;
        }
        int start = 0;
        for(int len = 1;len<=s.size();len++){
            string x = s.substr(start,len);
            if(ispalindrome(x)){
                v.push_back(x);
                string y = s.substr(len, s.size()-len);
                func(y,v,ans);
                v.pop_back();
            }
        }
        
    }
    bool ispalindrome(string s){
        string t = s;
        reverse(s.begin(),s.end());
        return t==s;
    }
        vector<vector<string>> partition(string s){
        vector<vector<string>> ans;
        vector<string>v = {};
        func(s,v,ans);
        return ans;
    }
};