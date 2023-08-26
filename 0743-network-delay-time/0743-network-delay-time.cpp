class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> dist(n+1, 1e9);
        dist[0] = 0;
        dist[k] = 0;

        for(int i=0; i<n; ++i){
            for(auto it:times){
                int u = it[0];
                int v = it[1];
                int eW = it[2];

                if(dist[u] != 1e9 and dist[u]+eW < dist[v])
                dist[v] = dist[u]+eW;
            }
        }
        int ans = 0;
        for(auto it:dist){
            if(it==1e9) return -1;
            ans = max(ans,it);
        }
        return ans;
    }
};