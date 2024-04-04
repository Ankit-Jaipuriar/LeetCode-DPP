class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int depth=0;
        for(char i:s){
            if(i=='('){
                st.push(i);
            }else if(i==')'){
                depth = max(depth, static_cast<int>(st.size()));
                st.pop();
            }
        }
        return depth;
    }
};