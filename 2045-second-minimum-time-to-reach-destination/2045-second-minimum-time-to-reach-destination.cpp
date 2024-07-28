class Solution {
public:
    #define p pair<int,int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>adj[n+1];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 1});
        
        vector<int>dist1(n+1, 1e9), dist2(n+1, 1e9);
        dist1[1] = 0;

        while(!pq.empty()){
            auto [timePassed, node] = pq.top();
            pq.pop();

            if(node==n && dist2[n] != 1e9)
            return dist2[n];

            int rem = timePassed / change;
            if(rem % 2){
                timePassed = (timePassed/change + 1) * change;
            }

            for(auto child : adj[node]){
                if(dist1[child] > timePassed + time){
                    dist2[child] = dist1[child];
                    dist1[child] = timePassed + time;
                    pq.push({dist1[child], child});
                }
                else if(dist2[child] > timePassed+time && dist1[child] != timePassed+time){
                    dist2[child] = timePassed+time;
                    pq.push({dist2[child], child});
                }
            }
        }
        return -1;
    }
};