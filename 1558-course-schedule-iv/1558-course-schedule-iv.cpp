class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p:prerequisites){
            int u=p[0],v=p[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        vector<vector<int>> pathVisited(numCourses, vector<int>(numCourses,false));
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto nbr:graph[curr]){
                pathVisited[curr][nbr]=true;

                for(int i=0;i<numCourses;i++){
                    if(pathVisited[i][curr]){
                        pathVisited[i][nbr]=true;
                    }
                }

                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        vector<bool> res;
        for(auto q:queries){
            int x = q[0],y=q[1];

            res.push_back(pathVisited[x][y]);
        }
        return res;



    }
};