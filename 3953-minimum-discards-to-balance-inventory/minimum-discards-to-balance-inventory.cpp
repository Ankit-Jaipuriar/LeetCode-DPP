class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n=arrivals.size();
        //m - most occurence allowed
        //w - window range [i,j]

        int count=0;
        unordered_map<int,int> freq;
        queue<int> window;
        for(int i=0;i<n;i++){
            int item = arrivals[i];

            if(window.size()==w){
                int old = window.front();
                window.pop();
                if(old!=INT_MIN){
                    freq[old]--;
                }
            }

            if(freq[item]<m){
                window.push(item);
                freq[item]++;
            }else{
                window.push(INT_MIN);
                count++;
            }
        }
        return count;
    }
};