class Solution {
public:
    bool solve(int i, int j,string& s1, string& s2){
        if(i==s1.size()) return true;
        if(j==s2.size()) return false;
        if(s1[i]==s2[j]){
            return solve(i+1,j+1,s1,s2);
        }
           return solve(i,j+1,s1,s2);
    }
    bool isSubsequence(string s, string t) {
        return solve(0,0,s,t);
    }
};