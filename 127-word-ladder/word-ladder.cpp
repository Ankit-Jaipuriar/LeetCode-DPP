class Solution {
public:
    bool isConnected(string a, string b){
        int diff=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) diff++;
            if(diff>1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> wordGraph;
        auto itr = find(wordList.begin(),wordList.end(),endWord);
        if(itr==wordList.end()) return 0;

        wordList.push_back(beginWord);
        int n = wordList.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected(wordList[i],wordList[j])){
                    wordGraph[wordList[i]].push_back(wordList[j]);
                    wordGraph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        unordered_map<string,bool> vis;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        vis[beginWord]=true;

        while(!q.empty()){
            string curr = q.front().first;
            int num = q.front().second;
            q.pop();
            if(curr==endWord) return num;
            for(string neighbor:wordGraph[curr]){
                if(!vis[neighbor]){
                    vis[neighbor]=true;
                    q.push({neighbor,num+1});
                }
            }
        }
        return 0;

    }
};