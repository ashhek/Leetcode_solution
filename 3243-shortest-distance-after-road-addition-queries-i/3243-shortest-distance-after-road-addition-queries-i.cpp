class Solution {
    int m;
    int dijestra(int src, int dest, vector<int>adj[]){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(m, 1e9);
        pq.push({0, src});
        dist[0] = 0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it;
                if(dis + 1 < dist[adjNode]){
                    dist[adjNode] = dis+1;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist[m-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];

        m = n;

        for(int i=0; i<n; ++i){
            if(i==n-1) break;

            adj[i].push_back(i+1);
        }
        vector<int>ans;

        for(auto it : queries){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);

            int x = dijestra(0, n-1, adj);
            ans.push_back(x);
        }
        return ans;
    }
};