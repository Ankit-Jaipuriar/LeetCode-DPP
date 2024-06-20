class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> st;
       for(auto x:asteroids){
        if(x>0) st.push(x);
        else{
            while(!st.empty() and st.top()>0 and st.top()<(x*-1)){
                st.pop();
            }
            if(!st.empty() and st.top()>0 and st.top()==(x*-1)){
                st.pop();
            }else if(!st.empty() and st.top()>(x*-1)){
                continue;
            }else{
                st.push(x);
            }
        }
       }
       vector<int>ans;
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
       }  
       reverse(ans.begin(),ans.end());
       return ans;
         
    }
};