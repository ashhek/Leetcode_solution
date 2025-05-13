class Solution {
public:
    #define pp pair<int,pair<int,int>>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, src}});
        vector<int>dist(n, 1e9);
        dist[src] = 0;

        while(!pq.empty()) {
            int stop = pq.top().first;
            int currCost = pq.top().second.first;
            int node = pq.top().second.second;
            pq.pop();

            if(stop > k) {
                break;
            }

            for(auto [child, childCost] : adj[node]) {
                if(currCost + childCost < dist[child]) {
                    dist[child] = currCost + childCost;
                    pq.push({stop+1, {dist[child], child}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};