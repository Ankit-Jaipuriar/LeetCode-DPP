class Solution {
public:
    struct node{
        int distance;
        int vertex;
        int stops;
    };

    struct cmp{
        bool operator()(node a, node b){
            if(a.distance==b.distance){
                return a.vertex>b.vertex;
            }
            return a.distance>b.distance;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<flights.size();i++){
            int x,y,z;
            x=flights[i][0];
            y=flights[i][1];
            z=flights[i][2];
            graph[x].push_back({y,z});
        }

        priority_queue<node, vector<node>, cmp> pq;
        pq.push({0,src,0});

        vector<vector<int>> distance(n, vector<int>(k+2,INT_MAX));
        distance[src][0]=0;

        while(!pq.empty()){
            int currdist=pq.top().distance;
            int currvert=pq.top().vertex;
            int currstops=pq.top().stops;
            pq.pop();

            if(currvert==dst){
                return currdist;
            }

            if(currstops>k){
                continue;
            }

            for(auto nb:graph[currvert]){
                int nbr=nb.first;
                int weight=nb.second;

                if(currdist+weight<distance[nbr][currstops+1]){
                    distance[nbr][currstops+1]=currdist+weight;
                    pq.push({distance[nbr][currstops+1], nbr, currstops+1});
                }
            }
        }

        int mini=INT_MAX;
        for(int i=0;i<=k+1;i++){
            mini=min(mini, distance[dst][i]);
        }

        return mini==INT_MAX ? -1:mini;

    }
};
