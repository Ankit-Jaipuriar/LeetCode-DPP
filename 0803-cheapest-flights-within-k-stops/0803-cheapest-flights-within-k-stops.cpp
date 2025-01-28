class Solution {
public:

    struct Node {
        int distance;
        int vertex;
        int stops;
    };

    struct cmp {
        bool operator()(Node a, Node b) {
            if (a.distance == b.distance) {
                return a.vertex > b.vertex; 
            }
            return a.distance > b.distance; 
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int, int>>> graph(n);
        for (auto i : flights) {
            graph[i[0]].push_back({i[1], i[2]});
        }

        // Use 2D vector to track the minimum distance to a node with a given number of stops
        vector<vector<int>> distance(n, vector<int>(k + 2, INT_MAX));
        distance[src][0] = 0;

        priority_queue<Node, vector<Node>, cmp> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            int currDistance = pq.top().distance;
            int currVertex = pq.top().vertex;
            int currStops = pq.top().stops;
            pq.pop();

            if (currVertex == dst) {
                return currDistance;
            }

            if (currStops > k) {
                continue;
            }

            for (auto u : graph[currVertex]) {
                int neighbor = u.first;
                int weight = u.second;
                if (currDistance + weight < distance[neighbor][currStops + 1]) {
                    distance[neighbor][currStops + 1] = currDistance + weight;
                    pq.push({distance[neighbor][currStops + 1], neighbor, currStops + 1});
                }
            }
        }

        int minDistance = INT_MAX;
        for (int i = 0; i <= k + 1; i++) {
            minDistance = min(minDistance, distance[dst][i]);
        }

        return minDistance == INT_MAX ? -1 : minDistance;
    }
};
