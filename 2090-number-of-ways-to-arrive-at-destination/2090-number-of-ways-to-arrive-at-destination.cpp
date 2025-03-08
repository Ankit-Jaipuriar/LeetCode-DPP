class Solution {
public:
    struct node{
        long long distance; 
        int vertex;
    };

    struct cmp{
        bool operator()(node a, node b){
            if(a.distance==b.distance){
                return a.vertex>b.vertex;
            }
            return a.distance>b.distance;
        }
    };

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        const int MOD = 1e9 + 7;

        for(int i=0; i<roads.size(); i++){
            int x = roads[i][0];
            int y = roads[i][1];
            int z = roads[i][2];

            // Bidirectional graph
            graph[x].push_back({y,z});
            graph[y].push_back({x,z});
        }

        int src = 0;
        int dst = n-1;

        priority_queue<node, vector<node>, cmp> pq;
        pq.push({0,src});

        vector<long long> distance(n, LLONG_MAX); 
        distance[src] = 0;

        vector<int> dp(n, 0);
        dp[src] = 1;  // Number of ways to reach vertex i

        while(!pq.empty()){
            long long currdist = pq.top().distance;
            int currvert = pq.top().vertex;
            pq.pop();

            if(distance[currvert] == currdist){
                for(auto nb : graph[currvert]){
                    int nbr = nb.first;
                    long long weight = nb.second;

                    if(currdist + weight < distance[nbr]){
                        distance[nbr] = currdist + weight;
                        dp[nbr] = dp[currvert]; // Reset dp if smaller path is found
                        pq.push({distance[nbr], nbr});
                    } else if(currdist + weight == distance[nbr]){
                        dp[nbr] = (dp[nbr] + dp[currvert]) % MOD;
                    }
                }
            }
        }

        return dp[dst];
    }
};
