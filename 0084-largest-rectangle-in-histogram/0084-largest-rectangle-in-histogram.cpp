class Solution {
public:
    vector<int> nextSmaller(int n, vector<int>& heights){
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(int n, vector<int>& heights){
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prev(n);
        prev = prevSmaller(n,heights);
        vector<int> next(n);
        next = nextSmaller(n,heights);

        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            int len = heights[i];

            if(next[i]==-1){
                next[i]=n;
            }

            int breadth = next[i]-prev[i]-1;
            int area = len*breadth;
            ans = max(ans,area);
        }
        return ans;
    }
};