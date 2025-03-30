class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

        for(int i=0;i<n;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            count++;

            if(count==numCourses) return true;

            for(auto nbr:graph[curr]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
            }
        }
        return false;
    }
};