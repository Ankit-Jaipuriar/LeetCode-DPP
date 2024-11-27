class Solution {
public:
struct data{
    string word;
    int freq;
};
static bool cmp(data d1, data d2){
    if(d1.freq==d2.freq){
        return d1.word<d2.word;
    }
    return d1.freq>d2.freq;
}
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto word:words){
            mp[word]++;
        }
        vector<data> v;
        for(auto p:mp){
            v.push_back({p.first,p.second});
        }
        sort(v.begin(),v.end(),cmp);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].word);
        }
        return ans;

    }
};