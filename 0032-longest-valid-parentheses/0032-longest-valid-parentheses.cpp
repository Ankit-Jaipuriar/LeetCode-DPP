class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0,maxlen=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(') left++;
            else if(s[i]==')') right++;

            if(left==right) maxlen = max(maxlen, left*2);
            else if(right>left){
                right=0,left=0;
            }
        }
        left=0,right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') left++;
            else if(s[i]==')') right++;

            if(left==right) maxlen = max(maxlen, left*2);
            else if(right<left){
                right=0,left=0;
            }
            
        }
        return maxlen;
    }
};