#include <string>
#include <stack>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        std::stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop(); 
                } else {
                    s.erase(i, 1); 
                    --i; 
                }
            }
        }

        while (!st.empty()) {
            s.erase(st.top(), 1);
            st.pop();
        }
        
        return s;
    }
};
