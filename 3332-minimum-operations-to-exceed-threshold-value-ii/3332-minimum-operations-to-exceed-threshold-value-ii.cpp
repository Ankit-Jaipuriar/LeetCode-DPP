class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for (int num : nums) {
            pq.push(num);
        }

        int count = 0;
        long long x,y;
        while (pq.top() < k) {
           x=pq.top();
           pq.pop();
           if(!pq.empty()){
            y=pq.top();
            pq.pop();
            pq.push((long long)x*2+y);
            count++;
           }else{
            break;
           }
        }
        
        return count;
    }
};
