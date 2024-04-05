class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> st;
        string res="";
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() && (st.top()-s[i]==32 || st.top()-s[i]==-32)){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};