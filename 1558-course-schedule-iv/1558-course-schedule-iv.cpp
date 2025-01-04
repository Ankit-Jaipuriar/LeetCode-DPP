class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }

        queue<int> q;
        vector<unordered_set<int>> reachable(numCourses); 

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : adj[curr]) {
                reachable[next].insert(curr);
                for (int pre : reachable[curr]) {
                    reachable[next].insert(pre);
                }

                inDegree[next]--;
                if (inDegree[next] == 0) q.push(next);
            }
        }

        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(reachable[query[1]].count(query[0]) > 0);
        }

        return result;
    }
};
