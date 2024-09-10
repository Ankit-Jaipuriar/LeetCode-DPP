class Solution {
public:
    bool dfs(int curr, int n, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& visiting){
        visiting[curr]=true;
        for(auto neighbor:graph[curr]){
            if(visiting[neighbor]) return false;
            if(!visited[neighbor]){
                if(!dfs(neighbor, n, graph, visited, visiting)) return false;
            }
        }
        visiting[curr]=false;
        visited[curr]=true;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto prequisite:prerequisites){
            graph[prequisite[0]].push_back(prequisite[1]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> visiting(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(i,numCourses,graph,visited,visiting)) return false;
            }
        }
        return true;
    }
};