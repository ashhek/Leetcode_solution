class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];

        int ind = 0;
        for(auto edge : edges) {
            adj[edge[0]].push_back({edge[1], succProb[ind]});
            adj[edge[1]].push_back({edge[0], succProb[ind]});
            ind++;
        }
        priority_queue<pair<double, int>>pq;
        pq.push({1.0, start_node});

        vector<double>prob(n, 0);
        prob[start_node] = 1;

        while(!pq.empty()) {
            double dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto child : adj[node]) {
                int adjNode = child.first;
                double edgW = child.second;

                if(dis*edgW > prob[adjNode]) {
                    prob[adjNode] = dis*edgW;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }
        return prob[end_node];
    }
};