class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        set<string> wordSet;
        map<string, bool> visited;
        visited[beginWord] = true;

        for (int i = 0; i < n; i++) {
            wordSet.insert(wordList[i]);
        }

        if (wordSet.find(endWord) == wordSet.end()) return 0; // Ensure endWord exists

        // Add beginWord to adjacency list
        map<string, vector<string>> adj;
        wordSet.insert(beginWord); // Ensure it's in the set for adjacency calculation

        for (auto word : wordSet) {
            for (int j = 0; j < word.size(); j++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    string newWord = word.substr(0, j);
                    newWord += c;
                    newWord += word.substr(j + 1, word.size() - j - 1);

                    if (newWord != word && wordSet.find(newWord) != wordSet.end()) {
                        adj[word].push_back(newWord);
                    }
                }
            }
        }

        // BFS
        int level = 1;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = true;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();

                if (curr == endWord) return level;

                for (auto nbr : adj[curr]) {
                    if (!visited[nbr]) {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};
