class Solution {
public:
vector<string> v;
    void helper(int open, int close, int n, string temp){
        if(temp.length()==2*n){
            v.push_back(temp);
            return;
        }
        if(open<n){
            helper(open+1,close,n,temp+'(');
        }
        if(close<open){
            helper(open,close+1,n,temp+')');
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        v.clear();
        helper(0,0,n,"");
        return v;
    }
};