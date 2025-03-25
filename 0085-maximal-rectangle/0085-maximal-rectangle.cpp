class Solution {
public:
    vector<int> nextSmall(vector<int>& heights, int m){
        vector<int> ans(m);
        stack<int> s;
        s.push(-1);

        for(int i=m-1;i>=0;i--){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmall(vector<int>& heights, int m){
        vector<int> ans(m);
        stack<int> s;
        s.push(-1);

        for(int i=0;i<m;i++){
            int curr=heights[i];
            while(s.top()!=-1 && heights[s.top()]>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangle(vector<int>& heights, int m){
        vector<int> prev(m);
        prev = prevSmall(heights,m);
        vector<int> next(m);
        next = nextSmall(heights,m);

        int area = INT_MIN;
        for(int i=0;i<m;i++){
            int len=heights[i];

            if(next[i]==-1){
                next[i]=m;
            }
            int b = next[i]-prev[i]-1;
            area = max(area,len*b);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        for(int j = 0; j < m; j++) {
            heights[j] = (matrix[0][j] == '1') ? 1 : 0;
        }
        
        int area = largestRectangle(heights, m);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            area = max(area, largestRectangle(heights, m));
        }
        return area;
    }
};