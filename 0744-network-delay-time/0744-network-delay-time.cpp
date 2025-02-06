class Solution {
public:
    struct node {
        int distance;
        int vertex;
    };

    struct cmp {
        bool operator()(node n1, node n2) {
            if (n1.distance == n2.distance) {
                return n1.vertex > n2.vertex;
            }
            return n1.distance > n2.distance;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int x = times[i][0];
            int y = times[i][1];
            int z = times[i][2];
            adj[x].push_back({y, z});
        }

        vector<int> distance(n + 1, INT_MAX);
        int source = k;
        priority_queue<node, vector<node>, cmp> pq;
        pq.push({0, source});
        distance[source] = 0;

        while (!pq.empty()) {
            int currdist = pq.top().distance;
            int currvert = pq.top().vertex;
            pq.pop(); 

            if (currdist == distance[currvert]) {
                for (auto node : adj[currvert]) {
                    int nbr = node.first;
                    int weight = node.second;

                    if (currdist + weight < distance[nbr]) {
                        distance[nbr] = currdist + weight;
                        pq.push({distance[nbr], nbr});
                    }
                }
            }
        }

        int maxi = *max_element(distance.begin() + 1, distance.end());
        return maxi == INT_MAX ? -1 : maxi;
    }
};
