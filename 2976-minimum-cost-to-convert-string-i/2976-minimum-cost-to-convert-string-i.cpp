class Solution {
    int n;
    long long help(int src, int dest, vector<pair<int,int>>adj[]){

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, src});
        vector<long long>dist(26, 1e9);
        dist[src] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            for(auto child : adj[node]){
                long long edw = child.second;
                int adjNode = child.first;

                if(edw+dis < dist[adjNode]){
                    dist[adjNode] = edw + dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return (dist[dest] >= 1e9 ? -1 : dist[dest]);

    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
         n = cost.size();
         vector<pair<int, int>> adj[26];

        for(int i=0; i<n; ++i){
            adj[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
        }

        long long ans = 0;

        vector<vector<int>>dp(26, vector<int>(26, -1));

        for(int i=0; i<source.size(); ++i){
            if(dp[source[i]-'a'][target[i]-'a'] != -1) {
                ans += dp[source[i]-'a'][target[i]-'a'];
                continue;
            }
            if(source[i] != target[i]){
                long long x = help(source[i]-'a', target[i]-'a', adj);
                if(x==-1) return -1;
                ans += x;
                dp[source[i]-'a'][target[i]-'a'] = x;
            }
        }
        return ans;
    }
};