class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n+1];

        for(auto it:times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        
        dist[0] = 0;
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int adjNode = it.first;
                int eW = it.second;

                if(dis+eW < dist[adjNode]){
                    dist[adjNode] = dis+eW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for(int i=0; i<=n; ++i){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};