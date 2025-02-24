class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=2;i<=n;i++){
            string temp="";
            int sz=ans.size();
            for(int j=0;j<sz;j++){
                int count=1;
                while(j+1<sz && ans[j]==ans[j+1]){
                    count++;
                    j++;
                }
                temp+=to_string(count)+ans[j];
            }
            ans=temp;
        }
        return ans;
    }
};