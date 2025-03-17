class Solution {
public:
    struct node{
        int freq;
        string word;
    };

    struct cmp{
        bool operator()(node a, node b){
            if(a.freq==b.freq){
                return a.word<b.word;
            }
            return a.freq>b.freq;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        priority_queue<node, vector<node>, cmp> pq;

        for(auto freq:mp){
            pq.push({freq.second, freq.first});
            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().word);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};